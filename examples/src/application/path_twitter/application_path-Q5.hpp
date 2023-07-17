#ifndef APPLICATION_PATH_Q5_BASE_HPP
#define APPLICATION_PATH_Q5_BASE_HPP

#include "../application.hpp"

const string dataPath = "data/ego-twitter";

void Application::init_relations() {
	clear_relations();

#if defined(RELATION_R1_STATIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R1_entry>(
            "R1", dataPath + "/R1.tbl", '|', true,
            [](dbtoaster::data_t& data) {
                return [&](R1_entry& t) {
                    data.on_insert_R1(t);
                };
            }
    )));
#elif defined(RELATION_R1_DYNAMIC) && defined(BATCH_SIZE)
    typedef const std::vector<DELTA_R1_entry>::iterator CIteratorR1;
    relations.push_back(std::unique_ptr<IRelation>(
        new BatchDispatchableRelation<DELTA_R1_entry>(
            "R1", dataPath + "/R1.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](CIteratorR1& begin, CIteratorR1& end) {
                    data.on_batch_update_R1(begin, end);
                };
            }
    )));
#elif defined(RELATION_R1_DYNAMIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R1_entry>(
            "R1", dataPath + "/R1.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](R1_entry& t) {
                    data.on_insert_R1(t);
                };
            }
    )));
#endif
#if defined(RELATION_R2_STATIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R2_entry>(
            "R2", dataPath + "/R2.tbl", '|', true,
            [](dbtoaster::data_t& data) {
                return [&](R2_entry& t) {
                    data.on_insert_R2(t);
                };
            }
    )));
#elif defined(RELATION_R2_DYNAMIC) && defined(BATCH_SIZE)
    typedef const std::vector<DELTA_R2_entry>::iterator CIteratorR2;
    relations.push_back(std::unique_ptr<IRelation>(
        new BatchDispatchableRelation<DELTA_R2_entry>(
            "R2", dataPath + "/R2.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](CIteratorR2& begin, CIteratorR2& end) {
                    data.on_batch_update_R2(begin, end);
                };
            }
    )));
#elif defined(RELATION_R2_DYNAMIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R2_entry>(
            "R2", dataPath + "/R2.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](R2_entry& t) {
                    data.on_insert_R2(t);
                };
            }
    )));
#endif
#if defined(RELATION_R3_STATIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R3_entry>(
            "R3", dataPath + "/R3.tbl", '|', true,
            [](dbtoaster::data_t& data) {
                return [&](R3_entry& t) {
                    data.on_insert_R3(t);
                };
            }
    )));
#elif defined(RELATION_R3_DYNAMIC) && defined(BATCH_SIZE)
    typedef const std::vector<DELTA_R3_entry>::iterator CIteratorR3;
    relations.push_back(std::unique_ptr<IRelation>(
        new BatchDispatchableRelation<DELTA_R3_entry>(
            "R3", dataPath + "/R3.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](CIteratorR3& begin, CIteratorR3& end) {
                    data.on_batch_update_R3(begin, end);
                };
            }
    )));
#elif defined(RELATION_R3_DYNAMIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R3_entry>(
            "R3", dataPath + "/R3.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](R3_entry& t) {
                    data.on_insert_R3(t);
                };
            }
    )));
#endif
#if defined(RELATION_R4_STATIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R4_entry>(
            "R4", dataPath + "/R4.tbl", '|', true,
            [](dbtoaster::data_t& data) {
                return [&](R4_entry& t) {
                    data.on_insert_R4(t);
                };
            }
    )));
#elif defined(RELATION_R4_DYNAMIC) && defined(BATCH_SIZE)
    typedef const std::vector<DELTA_R4_entry>::iterator CIteratorR4;
    relations.push_back(std::unique_ptr<IRelation>(
        new BatchDispatchableRelation<DELTA_R4_entry>(
            "R4", dataPath + "/R4.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](CIteratorR4& begin, CIteratorR4& end) {
                    data.on_batch_update_R4(begin, end);
                };
            }
    )));
#elif defined(RELATION_R4_DYNAMIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R4_entry>(
            "R4", dataPath + "/R4.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](R4_entry& t) {
                    data.on_insert_R4(t);
                };
            }
    )));
#endif
#if defined(RELATION_R5_STATIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R5_entry>(
            "R5", dataPath + "/R5.tbl", '|', true,
            [](dbtoaster::data_t& data) {
                return [&](R5_entry& t) {
                    data.on_insert_R5(t);
                };
            }
    )));
#elif defined(RELATION_R5_DYNAMIC) && defined(BATCH_SIZE)
    typedef const std::vector<DELTA_R5_entry>::iterator CIteratorR5;
    relations.push_back(std::unique_ptr<IRelation>(
        new BatchDispatchableRelation<DELTA_R5_entry>(
            "R5", dataPath + "/R5.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](CIteratorR5& begin, CIteratorR5& end) {
                    data.on_batch_update_R5(begin, end);
                };
            }
    )));
#elif defined(RELATION_R5_DYNAMIC)
    relations.push_back(std::unique_ptr<IRelation>(
        new EventDispatchableRelation<R5_entry>(
            "R5", dataPath + "/R5.tbl", '|', false,
            [](dbtoaster::data_t& data) {
                return [&](R5_entry& t) {
                    data.on_insert_R5(t);
                };
            }
    )));
#endif

}	void Application::on_snapshot(dbtoaster::data_t& data) {
		on_end_processing(data, false);
	}

	void Application::on_begin_processing(dbtoaster::data_t& data) {

	}

	void Application::on_end_processing(dbtoaster::data_t& data, bool print_result) {
		if (print_result) {
			data.serialize(std::cout, 0);
		}
	}



#endif /* APPLICATION_PATH_Q5_BASE_HPP */

