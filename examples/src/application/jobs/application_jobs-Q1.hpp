#ifndef APPLICATION_JOBS_Q1_BASE_HPP
#define APPLICATION_JOBS_Q1_BASE_HPP

#include "../application.hpp"

const string dataPath = "data/imdb";

void Application::init_relations() {
    clear_relations();

    // title
    #if defined(RELATION_TITLE_STATIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<TITLE_entry>(
                "title", dataPath + "/title.csv", ',', true,
                [](dbtoaster::data_t& data) {
                    return [&](TITLE_entry& t) {
                        data.on_insert_TITLE(t);
                    };
                }
        )));
    #elif defined(RELATION_TITLE_DYNAMIC) && defined(BATCH_SIZE)
        typedef const std::vector<DELTA_TITLE_entry>::iterator CIteratorTitle;
        relations.push_back(std::unique_ptr<IRelation>(
            new BatchDispatchableRelation<DELTA_TITLE_entry>(
                "title", dataPath + "/title.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](CIteratorTitle& begin, CIteratorTitle& end) {
                        data.on_batch_update_TITLE(begin, end);
                    };
                }
        )));
    #elif defined(RELATION_TITLE_DYNAMIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<TITLE_entry>(
                "title", dataPath + "/title.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](TITLE_entry& t) {
                        data.on_insert_TITLE(t);
                    };
                }
        )));
    #endif


    // company_type
    #if defined(RELATION_COMPANY_TYPE_STATIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<COMPANY_TYPE_entry>(
                "company_type", dataPath + "/company_type.csv", ',', true,
                [](dbtoaster::data_t& data) {
                    return [&](COMPANY_TYPE_entry& t) {
                        data.on_insert_COMPANY_TYPE(t);
                    };
                }
        )));
    #elif defined(RELATION_COMPANY_TYPE_DYNAMIC) && defined(BATCH_SIZE)
        typedef const std::vector<DELTA_COMPANY_TYPE_entry>::iterator CIteratorCompany_type;
        relations.push_back(std::unique_ptr<IRelation>(
            new BatchDispatchableRelation<DELTA_COMPANY_TYPE_entry>(
                "company_type", dataPath + "/company_type.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](CIteratorCompany_type& begin, CIteratorCompany_type& end) {
                        data.on_batch_update_COMPANY_TYPE(begin, end);
                    };
                }
        )));
    #elif defined(RELATION_COMPANY_TYPE_DYNAMIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<COMPANY_TYPE_entry>(
                "company_type", dataPath + "/company_type.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](COMPANY_TYPE_entry& t) {
                        data.on_insert_COMPANY_TYPE(t);
                    };
                }
        )));
    #endif

    // info_type
    #if defined(RELATION_INFO_TYPE_STATIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<INFO_TYPE_entry>(
                "info_type", dataPath + "/info_type.csv", ',', true,
                [](dbtoaster::data_t& data) {
                    return [&](INFO_TYPE_entry& t) {
                        data.on_insert_INFO_TYPE(t);
                    };
                }
        )));
    #elif defined(RELATION_INFO_TYPE_DYNAMIC) && defined(BATCH_SIZE)
        typedef const std::vector<DELTA_INFO_TYPE_entry>::iterator CIteratorInfo_type;
        relations.push_back(std::unique_ptr<IRelation>(
            new BatchDispatchableRelation<DELTA_INFO_TYPE_entry>(
                "info_type", dataPath + "/info_type.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](CIteratorInfo_type& begin, CIteratorInfo_type& end) {
                        data.on_batch_update_INFO_TYPE(begin, end);
                    };
                }
        )));
    #elif defined(RELATION_INFO_TYPE_DYNAMIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<INFO_TYPE_entry>(
                "info_type", dataPath + "/info_type.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](INFO_TYPE_entry& t) {
                        data.on_insert_INFO_TYPE(t);
                    };
                }
        )));
    #endif

    // movie_companies
    #if defined(RELATION_MOVIE_COMPANIES_STATIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<MOVIE_COMPANIES_entry>(
                "movie_companies", dataPath + "/movie_companies.csv", ',', true,
                [](dbtoaster::data_t& data) {
                    return [&](MOVIE_COMPANIES_entry& t) {
                        data.on_insert_MOVIE_COMPANIES(t);
                    };
                }
        )));
    #elif defined(RELATION_MOVIE_COMPANIES_DYNAMIC) && defined(BATCH_SIZE)
        typedef const std::vector<DELTA_MOVIE_COMPANIES_entry>::iterator CIteratorMovie_companies;
        relations.push_back(std::unique_ptr<IRelation>(
            new BatchDispatchableRelation<DELTA_MOVIE_COMPANIES_entry>(
                "movie_companies", dataPath + "/movie_companies.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](CIteratorMovie_companies& begin, CIteratorMovie_companies& end) {
                        data.on_batch_update_MOVIE_COMPANIES(begin, end);
                    };
                }
        )));
    #elif defined(RELATION_MOVIE_COMPANIES_DYNAMIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<MOVIE_COMPANIES_entry>(
                "movie_companies", dataPath + "/movie_companies.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](MOVIE_COMPANIES_entry& t) {
                        data.on_insert_MOVIE_COMPANIES(t);
                    };
                }
        )));
    #endif

    // movie_info_idx
    #if defined(RELATION_MOVIE_INFO_IDX_STATIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<MOVIE_INFO_IDX_entry>(
                "movie_info_idx", dataPath + "/movie_info_idx.csv", ',', true,
                [](dbtoaster::data_t& data) {
                    return [&](MOVIE_INFO_IDX_entry& t) {
                        data.on_insert_MOVIE_INFO_IDX(t);
                    };
                }
        )));
    #elif defined(RELATION_MOVIE_INFO_IDX_DYNAMIC) && defined(BATCH_SIZE)
        typedef const std::vector<DELTA_MOVIE_INFO_IDX_entry>::iterator CIteratorMovie_info_idx;
        relations.push_back(std::unique_ptr<IRelation>(
            new BatchDispatchableRelation<DELTA_MOVIE_INFO_IDX_entry>(
                "movie_info_idx", dataPath + "/movie_info_idx.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](CIteratorMovie_info_idx& begin, CIteratorMovie_info_idx& end) {
                        data.on_batch_update_MOVIE_INFO_IDX(begin, end);
                    };
                }
        )));
    #elif defined(RELATION_MOVIE_INFO_IDX_DYNAMIC)
        relations.push_back(std::unique_ptr<IRelation>(
            new EventDispatchableRelation<MOVIE_INFO_IDX_entry>(
                "movie_info_idx", dataPath + "/movie_info_idx.csv", ',', false,
                [](dbtoaster::data_t& data) {
                    return [&](MOVIE_INFO_IDX_entry& t) {
                        data.on_insert_MOVIE_INFO_IDX(t);
                    };
                }
        )));
    #endif


}	



void Application::on_snapshot(dbtoaster::data_t& data) {
    on_end_processing(data, false);
}

void Application::on_begin_processing(dbtoaster::data_t& data) {

}

void Application::on_end_processing(dbtoaster::data_t& data, bool print_result) {
    if (print_result) {
        data.serialize(std::cout, 0);
    }
}



#endif /* APPLICATION_JOBS_Q1_BASE_HPP */

