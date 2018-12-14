package fdbresearch

import fdbresearch.tree.{DTreeNode, DTreeRelation, Tree, ViewTree}
import fdbresearch.core.{SQL, SQLToM3Compiler, Source}
import fdbresearch.parsing.M3Parser

class Driver {

  import fdbresearch.tree.DTree._

  /**
    * Check if all SQL sources have consistent schemas with DTree relations
    */
  private def checkSchemas(sqlSources: List[Source], relations: List[DTreeRelation]): Unit = {
    val rm = relations.map { r =>
      r.name -> r.keys.map(v => (v.name, v.tp)).toSet
    }.toMap
    val diff = sqlSources.flatMap { s =>
      val f1 = s.schema.fields.toSet
      val f2 = rm(s.schema.name)
      f1.diff(f2).union(f2.diff(f1))
    }
    assert(diff.isEmpty, "Inconsistent schemas in SQL and DTree files:\n" + diff.mkString("\n"))
  }

  /**
    * Resolve missing types in SQL system
    */
  private def resolveTypes(s: SQL.System): SQL.System = {
    val vm = s.sources.flatMap(_.schema.fields.map(x => x._1 -> x._2)).toMap
    s.replace {
      case SQL.Field(n, t, tp) =>
        assert(tp == null || tp == vm(n))
        SQL.Field(n, t, vm(n))
    }.asInstanceOf[SQL.System]
  }

  def compile(sql: SQL.System, dtree: Tree[DTreeNode], batchUpdates: Boolean): String = {

    checkSchemas(sql.sources, dtree.getRelations)

    Main.logger.debug("CHECK SCHEMAS: OK")

    val typedSQL = resolveTypes(sql)
    val (terms, _, gb) = SQLToM3Compiler.compile(typedSQL)

    Main.logger.debug("BUILDING VIEW TREE:")

    val viewtree = ViewTree(dtree, gb.toSet, terms)

    Main.logger.debug("\n\nVIEW TREE:\n" + viewtree)

    val cg = new CodeGenerator(viewtree, sql.typeDefs, sql.sources, batchUpdates)
    val m3 = cg.generateM3
    Main.logger.debug("\n\nORIGINAL M3\n" + m3)

    val optM3 = Optimizer.optimize(m3)
    Main.logger.debug("\n\nOPTIMIZED M3\n" + optM3)

    // test that the output can be parsed by the M3 parser
    val checkedM3 = new M3Parser().apply(optM3.toString)
    Main.logger.debug("M3 SYNTAX CHECKED")

    checkedM3.toString
  }
}