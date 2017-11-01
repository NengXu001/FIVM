#include <sys/time.h>
#include <vector>
#include "macro.hpp"
#include "types.hpp"
#include "functions.hpp"
#include "hash.hpp"
#include "mmap.hpp"
#include "serialization.hpp"

#define RELATION_A1_STATIC
#define RELATION_A2_DYNAMIC
#define RELATION_A3_STATIC

namespace dbtoaster {
  
  /* Definitions of auxiliary maps for storing materialized views. */
  struct A2_entry {
    long i; long j; DOUBLE_TYPE __av; A2_entry* nxt; A2_entry* prv;
    explicit A2_entry() : nxt(nullptr), prv(nullptr) { }
    explicit A2_entry(const long c0, const long c1, const DOUBLE_TYPE c2) { i = c0; j = c1; __av = c2;  }
    A2_entry(const A2_entry& other) : i(other.i), j(other.j), __av(other.__av), nxt(nullptr), prv(nullptr) { }
    A2_entry(const std::vector<std::string>& f, const DOUBLE_TYPE v) { /* if (f.size() < 2) return; */ i = std::stol(f[0]); j = std::stol(f[1]); __av = v; nxt = nullptr; prv = nullptr; }
    FORCE_INLINE A2_entry& modify(const long c0, const long c1) { i = c0; j = c1;  return *this; }
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) const {
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, i);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, j);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, __av);
    }
  };
  
  struct A2_mapkey01_idxfn {
    FORCE_INLINE static size_t hash(const A2_entry& e) {
      size_t h = 0;
      hash_combine(h, e.i);
      hash_combine(h, e.j);
      return h;
    }
    FORCE_INLINE static bool equals(const A2_entry& x, const A2_entry& y) {
      return x.i == y.i && x.j == y.j;
    }
  };
  
  typedef MultiHashMap<A2_entry, DOUBLE_TYPE, 
    PrimaryHashIndex<A2_entry, A2_mapkey01_idxfn>
  > A2_map;
  
  typedef A2_entry DELTA_A2_entry;
  typedef A2_map DELTA_A2_map;
  struct A1_entry {
    long i; long j; DOUBLE_TYPE __av; A1_entry* nxt; A1_entry* prv;
    explicit A1_entry() : nxt(nullptr), prv(nullptr) { }
    explicit A1_entry(const long c0, const long c1, const DOUBLE_TYPE c2) { i = c0; j = c1; __av = c2;  }
    A1_entry(const A1_entry& other) : i(other.i), j(other.j), __av(other.__av), nxt(nullptr), prv(nullptr) { }
    A1_entry(const std::vector<std::string>& f, const DOUBLE_TYPE v) { /* if (f.size() < 2) return; */ i = std::stol(f[0]); j = std::stol(f[1]); __av = v; nxt = nullptr; prv = nullptr; }
    FORCE_INLINE A1_entry& modify(const long c0, const long c1) { i = c0; j = c1;  return *this; }
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) const {
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, i);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, j);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, __av);
    }
  };
  
  struct A1_mapkey01_idxfn {
    FORCE_INLINE static size_t hash(const A1_entry& e) {
      size_t h = 0;
      hash_combine(h, e.i);
      hash_combine(h, e.j);
      return h;
    }
    FORCE_INLINE static bool equals(const A1_entry& x, const A1_entry& y) {
      return x.i == y.i && x.j == y.j;
    }
  };
  
  typedef MultiHashMap<A1_entry, DOUBLE_TYPE, 
    PrimaryHashIndex<A1_entry, A1_mapkey01_idxfn>
  > A1_map;
  
  struct BASE_A2_entry {
    long i; long j; DOUBLE_TYPE __av; BASE_A2_entry* nxt; BASE_A2_entry* prv;
    explicit BASE_A2_entry() : nxt(nullptr), prv(nullptr) { }
    explicit BASE_A2_entry(const long c0, const long c1, const DOUBLE_TYPE c2) { i = c0; j = c1; __av = c2;  }
    BASE_A2_entry(const BASE_A2_entry& other) : i(other.i), j(other.j), __av(other.__av), nxt(nullptr), prv(nullptr) { }
    BASE_A2_entry(const std::vector<std::string>& f, const DOUBLE_TYPE v) { /* if (f.size() < 2) return; */ i = std::stol(f[0]); j = std::stol(f[1]); __av = v; nxt = nullptr; prv = nullptr; }
    FORCE_INLINE BASE_A2_entry& modify(const long c0, const long c1) { i = c0; j = c1;  return *this; }
    FORCE_INLINE BASE_A2_entry& modify0(const long c0) { i = c0;  return *this; }
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) const {
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, i);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, j);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, __av);
    }
  };
  
  struct BASE_A2_mapkey01_idxfn {
    FORCE_INLINE static size_t hash(const BASE_A2_entry& e) {
      size_t h = 0;
      hash_combine(h, e.i);
      hash_combine(h, e.j);
      return h;
    }
    FORCE_INLINE static bool equals(const BASE_A2_entry& x, const BASE_A2_entry& y) {
      return x.i == y.i && x.j == y.j;
    }
  };
  
  struct BASE_A2_mapkey0_idxfn {
    FORCE_INLINE static size_t hash(const BASE_A2_entry& e) {
      size_t h = 0;
      hash_combine(h, e.i);
      return h;
    }
    FORCE_INLINE static bool equals(const BASE_A2_entry& x, const BASE_A2_entry& y) {
      return x.i == y.i;
    }
  };
  
  typedef MultiHashMap<BASE_A2_entry, DOUBLE_TYPE, 
    PrimaryHashIndex<BASE_A2_entry, BASE_A2_mapkey01_idxfn>, 
    SecondaryHashIndex<BASE_A2_entry, BASE_A2_mapkey0_idxfn>
  > BASE_A2_map;
  
  struct A3_entry {
    long i; long j; DOUBLE_TYPE __av; A3_entry* nxt; A3_entry* prv;
    explicit A3_entry() : nxt(nullptr), prv(nullptr) { }
    explicit A3_entry(const long c0, const long c1, const DOUBLE_TYPE c2) { i = c0; j = c1; __av = c2;  }
    A3_entry(const A3_entry& other) : i(other.i), j(other.j), __av(other.__av), nxt(nullptr), prv(nullptr) { }
    A3_entry(const std::vector<std::string>& f, const DOUBLE_TYPE v) { /* if (f.size() < 2) return; */ i = std::stol(f[0]); j = std::stol(f[1]); __av = v; nxt = nullptr; prv = nullptr; }
    FORCE_INLINE A3_entry& modify(const long c0, const long c1) { i = c0; j = c1;  return *this; }
    FORCE_INLINE A3_entry& modify0(const long c0) { i = c0;  return *this; }
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) const {
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, i);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, j);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, __av);
    }
  };
  
  struct A3_mapkey01_idxfn {
    FORCE_INLINE static size_t hash(const A3_entry& e) {
      size_t h = 0;
      hash_combine(h, e.i);
      hash_combine(h, e.j);
      return h;
    }
    FORCE_INLINE static bool equals(const A3_entry& x, const A3_entry& y) {
      return x.i == y.i && x.j == y.j;
    }
  };
  
  struct A3_mapkey0_idxfn {
    FORCE_INLINE static size_t hash(const A3_entry& e) {
      size_t h = 0;
      hash_combine(h, e.i);
      return h;
    }
    FORCE_INLINE static bool equals(const A3_entry& x, const A3_entry& y) {
      return x.i == y.i;
    }
  };
  
  typedef MultiHashMap<A3_entry, DOUBLE_TYPE, 
    PrimaryHashIndex<A3_entry, A3_mapkey01_idxfn>, 
    SecondaryHashIndex<A3_entry, A3_mapkey0_idxfn>
  > A3_map;
  
  struct Q_entry {
    long i; long j; DOUBLE_TYPE __av; Q_entry* nxt; Q_entry* prv;
    explicit Q_entry() : nxt(nullptr), prv(nullptr) { }
    explicit Q_entry(const long c0, const long c1, const DOUBLE_TYPE c2) { i = c0; j = c1; __av = c2;  }
    Q_entry(const Q_entry& other) : i(other.i), j(other.j), __av(other.__av), nxt(nullptr), prv(nullptr) { }
    Q_entry(const std::vector<std::string>& f, const DOUBLE_TYPE v) { /* if (f.size() < 2) return; */ i = std::stol(f[0]); j = std::stol(f[1]); __av = v; nxt = nullptr; prv = nullptr; }
    FORCE_INLINE Q_entry& modify(const long c0, const long c1) { i = c0; j = c1;  return *this; }
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) const {
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, i);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, j);
      ar << ELEM_SEPARATOR;
      DBT_SERIALIZATION_NVP(ar, __av);
    }
  };
  
  struct Q_mapkey01_idxfn {
    FORCE_INLINE static size_t hash(const Q_entry& e) {
      size_t h = 0;
      hash_combine(h, e.i);
      hash_combine(h, e.j);
      return h;
    }
    FORCE_INLINE static bool equals(const Q_entry& x, const Q_entry& y) {
      return x.i == y.i && x.j == y.j;
    }
  };
  
  typedef MultiHashMap<Q_entry, DOUBLE_TYPE, 
    PrimaryHashIndex<Q_entry, Q_mapkey01_idxfn>
  > Q_map;
  
  struct tuple3_LL_D {
    long _1; long _2;  DOUBLE_TYPE __av; tuple3_LL_D* nxt; tuple3_LL_D* prv;
    explicit tuple3_LL_D() : nxt(nullptr), prv(nullptr) { }
    FORCE_INLINE tuple3_LL_D& modify(const long c0, const long c1) { _1 = c0; _2 = c1;  return *this; }
    static bool equals(const tuple3_LL_D &x, const tuple3_LL_D &y) {
      return ((x._1==y._1) && (x._2==y._2));
    }
    static long hash(const tuple3_LL_D &e) {
      size_t h = 0;
          hash_combine(h, e._1);
      hash_combine(h, e._2);
      return h;
    }
  };
  
  
  /* Type definition providing a way to access the results of the sql program */
  struct tlq_t {
    struct timeval t0, t; long tT, tN, tS;
    tlq_t(): tN(0), tS(0)  { gettimeofday(&t0, NULL); }
  
    /* Serialization Code */
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) const {
      ar << "\n";
      const Q_map& _Q = get_Q();
      dbtoaster::serialize_nvp_tabbed(ar, STRING(Q), _Q, "\t");
    }
  
    /* Functions returning / computing the results of top level queries */
    const Q_map& get_Q() const {
      return Q;
    }
  
  protected:
    /* Data structures used for storing / computing top level queries */
    Q_map Q;
  
  };
  
  /* Type definition providing a way to incrementally maintain the results of the sql program */
  struct data_t : tlq_t{
    data_t(): tlq_t(), agg1(16U) {
      
    }
  
  
    /* Trigger functions for table relations */
    void on_insert_A1(const long i, const long j, const DOUBLE_TYPE value) {
      A1_entry e(i, j, value);
      A1.insert(e);
    }
    void on_insert_A1(A1_entry &e, const DOUBLE_TYPE value) {
      e.__av = value;
      A1.insert(e);
    }
    void on_insert_A3(const long i, const long j, const DOUBLE_TYPE value) {
      A3_entry e(i, j, value);
      A3.insert(e);
    }
    void on_insert_A3(A3_entry &e, const DOUBLE_TYPE value) {
      e.__av = value;
      A3.insert(e);
    }

    
    /* Trigger functions for stream relations */
    void on_batch_update_A2(const std::vector<A2_entry>::iterator &begin, const std::vector<A2_entry>::iterator &end) {

      DELTA_A2.clear();
      int i = rand() % matrixSize;
      for (int j = 0; j < matrixSize; j++) {  
        de2.i = i;
        de2.j = j;
        de2.__av = (DOUBLE_TYPE) rand() / RAND_MAX;
        DELTA_A2.insert(de2);
      }
      
      tN += DELTA_A2.count();

      // cout << "DELTA_A2 = [ ";
      // for (int i = 0; i < matrixSize; i++) {
      //   for (int j = 0; j < matrixSize; j++) {
      //     cout << DELTA_A2.getValueOrDefault(de2.modify(i,j)) << " ";
      //   }
      //   cout << "; " << endl;
      // }
      // cout << "];" << endl;


      { //temp foreach
        DELTA_A2_entry* u = DELTA_A2.head;
        while(u) {
          long i = u->i;
          long j = u->j;
          DOUBLE_TYPE v1 = u->__av;
          BASE_A2.addOrDelOnZero(se1.modify(i, j), v1);
          u = u->nxt;
        }
      }

      agg1.clear();      
      { //foreach
        A1_entry* e2 = A1.head;
        while (e2) {
          long i = e2->i;
          long k = e2->j;
          DOUBLE_TYPE v2 = e2->__av;
          { //slice
            const SecondaryIdxNode<BASE_A2_entry>* n3_head = static_cast<const SecondaryIdxNode<BASE_A2_entry>*>(BASE_A2.slice(se3.modify0(k), 0));
            const SecondaryIdxNode<BASE_A2_entry>* n3 = n3_head;
            BASE_A2_entry* e3;
            while (n3) {
              e3 = n3->obj;
              long l = e3->j;
              DOUBLE_TYPE v3 = e3->__av;
              agg1.add(st1.modify(i, l), (v2 * v3));
              n3 = (n3 != n3_head ? n3->nxt : n3->child);
            }
          }
          e2 = e2->nxt;
        }
      }
      Q.clear();
      { //temp foreach
        tuple3_LL_D* e4 = agg1.head;
        while(e4) {
          long i = e4->_1;
          long l = e4->_2;
          DOUBLE_TYPE v4 = e4->__av;
          { //slice
            const SecondaryIdxNode<A3_entry>* n4_head = static_cast<const SecondaryIdxNode<A3_entry>*>(A3.slice(se4.modify0(l), 0));
            const SecondaryIdxNode<A3_entry>* n4 = n4_head;
            A3_entry* e5;
            while (n4) {
              e5 = n4->obj;
              long j = e5->j;
              DOUBLE_TYPE v5 = e5->__av;
              Q.addOrDelOnZero(se2.modify(i, j), (v4 * v5));
              n4 = (n4 != n4_head ? n4->nxt : n4->child);
            }
          }
          e4 = e4->nxt;
        
        }
      }

      // cout << "Q = [ ";
      // for (int i = 0; i < matrixSize; i++) {
      //   for (int j = 0; j < matrixSize; j++) {
      //     cout << Q.getValueOrDefault(se2.modify(i,j)) << " ";
      //   }
      //   cout << "; ";
      // }
      // cout << "];" << endl;
    }
    
    void on_system_ready_event() {
      /* initialize random seed: */
      srand (time(NULL));

      for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
          on_insert_A1(i, j, (DOUBLE_TYPE) rand() / RAND_MAX);
          on_insert_A3(i, j, (DOUBLE_TYPE) rand() / RAND_MAX);
          se3.i = i;
          se3.j = j;
          se3.__av = (DOUBLE_TYPE) rand() / RAND_MAX; 
          BASE_A2.insert(se3);          
        }
      }
      cout << endl << "Matrix size: " << matrixSize << "x" << matrixSize  << endl;
      cout << "Matrix A1 count: " << A1.count() <<  "    Matrix A2 count: " << BASE_A2.count() <<  "    Matrix A3 count: " << A3.count() << endl;
      
      // cout << "A1 = [ ";
      // for (int i = 0; i < matrixSize; i++) {
      //   for (int j = 0; j < matrixSize; j++) {
      //     cout << A1.getValueOrDefault(se5.modify(i,j)) << " ";
      //   }
      //   cout << "; ";
      // }
      // cout << "];" << endl;

      // cout << "A3 = [ ";
      // for (int i = 0; i < matrixSize; i++) {
      //   for (int j = 0; j < matrixSize; j++) {
      //     cout << A3.getValueOrDefault(se4.modify(i,j)) << " ";
      //   }
      //   cout << "; ";
      // }
      // cout << "];" << endl;      
    }
  
  private:
  
#ifdef MATRIX_SIZE
    const int matrixSize = MATRIX_SIZE;
#endif

    /* Sample entries for avoiding recreation of temporary objects */
    BASE_A2_entry se1;
    Q_entry se2;
    tuple3_LL_D st1;
    BASE_A2_entry se3;
    A3_entry se4;
    A2_entry de2;
    A1_entry se5;
  
    /* Data structures used for storing materialized views */
    A1_map A1;
    BASE_A2_map BASE_A2;
    A3_map A3;
    DELTA_A2_map DELTA_A2;
    MultiHashMap<tuple3_LL_D, DOUBLE_TYPE, PrimaryHashIndex<tuple3_LL_D> > agg1;
    
  
  };
}