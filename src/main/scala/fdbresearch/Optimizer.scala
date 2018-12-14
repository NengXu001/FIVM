package fdbresearch

import fdbresearch.util.Utils
import fdbresearch.core.M3

object Optimizer {

  def optimize(m3: M3.System): M3.System = {
    val (newTriggers, newMaps) = m3.triggers.map(optimizeTrigger).unzip
    M3.System(m3.typeDefs, m3.sources, m3.maps ++ newMaps.flatten, m3.queries, newTriggers)
  }

  private def optimizeTrigger(t: M3.Trigger): (M3.Trigger, List[M3.MapDef]) = {
    def optimizeStmts(stmts: List[M3.Statement], maps: List[M3.MapDef])
        : (List[M3.Statement], List[M3.MapDef]) = {
      val (optStmts, newMap) = optCSE(stmts)
      if (stmts == optStmts) (stmts, maps)
      else optimizeStmts(optStmts, maps ++ newMap)
    }
    val (stmts, newMaps) = optimizeStmts(t.stmts, Nil)
    (M3.Trigger(t.event, stmts.map(optimizeStatement)), newMaps)
  }

  private def optimizeStatement(s: M3.Statement): M3.Statement = s match {
    case M3.TriggerStmt(t, e, op, ie) =>
      M3.TriggerStmt(t, optimizeExpr(e), op, ie.map(optimizeExpr))
    case M3.IfStmt(cond, thenBlk, elseBlk) =>
      M3.IfStmt(cond, thenBlk.map(optimizeStatement), elseBlk.map(optimizeStatement))
  }

  def optimizeExpr(e: M3.Expr): M3.Expr = e.replace {
    case M3.AggSum(ks, e1) => optimizeExpr(e1) match {
      case M3.AggSum(_, e2) => M3.AggSum(ks, e2)    // Unnest AggSums

//      case M3.Mul(M3.AggSum(ks2, e2), r) =>
//        // Find product terms covered by ks2 and without maps in r
//        val (covered, rest) = prodList(r).partition { t =>
//          val (in, out) = t.schema
//          (in ++ out).toSet.subsetOf(ks2.toSet) &&     // singleton
//            !findMapsInExpr(t).exists(_.keys.nonEmpty) // no maps (expensive lookups)
//        }
//        val subterms = (prodList(e2) ++ covered).reduceRight(M3.Mul)
//        if (rest.isEmpty) M3.AggSum(ks, subterms)
//        else M3.AggSum(ks, (M3.AggSum(ks2, subterms) :: rest).reduceRight(M3.Mul))

      case e2 => M3.AggSum(ks, e2)
    }
  }

  private def findMapsInExpr(e: M3.Expr): List[M3.MapRef] =
    e.collect { case m: M3.MapRef => List(m) }

  private def prodList(e: M3.Expr): List[M3.Expr] = e match {
    case M3.Mul(l, r) => prodList(l) ++ prodList(r)
    case _ => List(e)
  }

  // CSE across statements, works with AggSums only
  private def optCSE(ss: List[M3.Statement]): (List[M3.Statement], Option[M3.MapDef]) = {
    // Replace src in statements with dst
    def replace(ss: List[M3.Statement], src: M3.Expr, dst: M3.MapRef): List[M3.Statement] = {
      def replaceInExpr(e: M3.Expr): M3.Expr = e.replace {
        case a: M3.AggSum => src.cmp(a) match {
          case Some (mapping) => M3.MapRef (dst.name, dst.tp, dst.keys.map(mapping), isTemp = true)
          case None => M3.AggSum(a.keys, replaceInExpr(a.e))
        }
      }
      def replaceInStatement(s: M3.Statement): M3.Statement = s match {
        case M3.TriggerStmt(target, e, op, ie) =>
          M3.TriggerStmt(target, replaceInExpr(e), op, ie.map(replaceInExpr))
        case M3.IfStmt(c, thenBlk, elseBlk) =>
          M3.IfStmt(c, thenBlk.map(replaceInStatement), elseBlk.map(replaceInStatement))
      }
      ss.map(replaceInStatement)
    }

    // Return all AggSum in statements
    def findAggregates(ss: List[M3.Statement]): List[M3.AggSum] = {
      def findInExpr(e: M3.Expr): List[M3.AggSum] =
        e.collect { case a: M3.AggSum => a :: findInExpr(a.e) }

      def findInStatement(s: M3.Statement): List[M3.AggSum] = s match {
        case M3.TriggerStmt(_, e, _, ie) =>
          findInExpr(e) ++ ie.map(findInExpr).getOrElse(Nil)
        case M3.IfStmt(_, thenBlk, elseBlk) =>
          findAggregates(thenBlk) ++ findAggregates(elseBlk)
      }
      ss.flatMap(findInStatement)
    }

    // Check if MapRef appears in statement
    def isReferencingMap(s: M3.Statement, m: M3.MapRef): Boolean = {
      def isMapRefInExpr(e: M3.Expr): Boolean =
        e.collect { case m2: M3.MapRef => List(m == m2) }.exists(identity)

      def isMapRefInStatement(s: M3.Statement): Boolean = s match {
        case M3.TriggerStmt(_, e, _, ie) =>
          isMapRefInExpr(e) || ie.exists(isMapRefInExpr)
        case M3.IfStmt(_, thenBlk, elseBlk) =>
          thenBlk.map(isMapRefInStatement).exists(identity) ||
            elseBlk.map(isMapRefInStatement).exists(identity)
      }
      isMapRefInStatement(s)
    }

//    def sortFn(e1: (M3.AggSum, Int), e2: (M3.AggSum, Int)): Boolean = {
//      def appearsIn(src: M3.AggSum, dst: M3.Expr): Boolean =
//        dst.collect {
//          case m: M3.AggSum => List(m == src || appearsIn(src, m.e))
//        }.exists(identity)
//      (e1._2 > e2._2) || (e1._2 == e2._2 && appearsIn(e2._1, e1._1))
//    }

    // Find candidates, ranked them by # of occurrences, replace top expression if > 1
    val candidates = findAggregates(ss)
    val ranked = candidates.groupBy(identity).mapValues(_.size).toList.sortWith(_._2 > _._2)
    ranked match {
      case (a, occurrences) :: _ if occurrences > 1 =>
        val tmpMapDef = M3.MapDef(Utils.fresh("TMP_SUM"), a.tp, a.keys, optimizeExpr(a))
        val tmpMapRef = M3.MapRef(tmpMapDef.name, tmpMapDef.tp, tmpMapDef.keys, isTemp = true)

        // Replace expression 'a' by tmpMapRef
        val replacedStmts = replace(ss, a, tmpMapRef)

        // Compute expression 'a' before first statement using tmpMapRef
        val indexFirst = replacedStmts.indexWhere(s => isReferencingMap(s, tmpMapRef))
        val stmts = replacedStmts.take(indexFirst) ++
          (M3.TriggerStmt(tmpMapRef, a, M3.OpSet, None) :: replacedStmts.drop(indexFirst))

        (stmts, Some(tmpMapDef))

      case _ => (ss, None)
    }
  }
}