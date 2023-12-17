#ifndef RINGJOBS1_HPP
#define RINGJOBS1_HPP

#include <limits>
#include <algorithm>

#include "types.hpp"
#include "serialization.hpp"

using namespace dbtoaster;

struct RingJobs1
{
    // STRING_TYPE production_note; // MIN(mc.note)
    // STRING_TYPE movie_title; // MIN(t.title)
    // int movie_year; // MIN(t.production_year)

    // production_note conditions
    // 1: all: NOT LIKE '%(as Metro-Goldwyn-Mayer Pictures)%'
    // 2: 1a, 1c: LIKE '%(co-production)%'
    // 3: 1b: LIKE '%(presents)%'
    // size_t count_production_note_cond1;
    // size_t count_production_note_cond2;
    // size_t count_production_note_cond3;

    size_t count_movie_title_1a;
    size_t count_movie_title_1b;
    size_t count_movie_title_1c;
    size_t count_movie_title_1d;

    int min_movie_year_1a;
    int min_movie_year_1b;
    int min_movie_year_1c;
    int min_movie_year_1d;

    size_t count_production_note_1a;
    size_t count_production_note_1b;
    size_t count_production_note_1c;
    size_t count_production_note_1d;

    explicit RingJobs1() : count_movie_title_1a(0), count_movie_title_1b(0), count_movie_title_1c(0), count_movie_title_1d(0), min_movie_year_1a(std::numeric_limits<int>::max()), min_movie_year_1b(std::numeric_limits<int>::max()), min_movie_year_1c(std::numeric_limits<int>::max()), min_movie_year_1d(std::numeric_limits<int>::max()), count_production_note_1a(0), count_production_note_1b(0), count_production_note_1c(0), count_production_note_1d(0) {}

    explicit RingJobs1(size_t count_movie_title_1a, size_t count_movie_title_1b, size_t count_movie_title_1c, size_t count_movie_title_1d, int min_movie_year_1a, int min_movie_year_1b, int min_movie_year_1c, int min_movie_year_1d,
                       size_t count_production_note_1a, size_t count_production_note_1b, size_t count_production_note_1c, size_t count_production_note_1d)
        : count_movie_title_1a(count_movie_title_1a), count_movie_title_1b(count_movie_title_1b), count_movie_title_1c(count_movie_title_1c), count_movie_title_1d(count_movie_title_1d), min_movie_year_1a(min_movie_year_1a), min_movie_year_1b(min_movie_year_1b), min_movie_year_1c(min_movie_year_1c), min_movie_year_1d(min_movie_year_1d), count_production_note_1a(count_production_note_1a), count_production_note_1b(count_production_note_1b), count_production_note_1c(count_production_note_1c), count_production_note_1d(count_production_note_1d) {}

    inline bool isZero() const
    {
        return count_movie_title_1a == 0 && count_movie_title_1b == 0 && count_movie_title_1c == 0 && count_movie_title_1d == 0 && min_movie_year_1a == std::numeric_limits<int>::max() && min_movie_year_1b == std::numeric_limits<int>::max() && min_movie_year_1c == std::numeric_limits<int>::max() && min_movie_year_1d == std::numeric_limits<int>::max() && count_production_note_1a == 0 && count_production_note_1b == 0 && count_production_note_1c == 0 && count_production_note_1d == 0;
    }

    RingJobs1 &operator+=(const RingJobs1 &r)
    {
        this->count_movie_title_1a += r.count_movie_title_1a;
        this->count_movie_title_1b += r.count_movie_title_1b;
        this->count_movie_title_1c += r.count_movie_title_1c;
        this->count_movie_title_1d += r.count_movie_title_1d;

        this->min_movie_year_1a = std::min(this->min_movie_year_1a, r.min_movie_year_1a);
        this->min_movie_year_1b = std::min(this->min_movie_year_1b, r.min_movie_year_1b);
        this->min_movie_year_1c = std::min(this->min_movie_year_1c, r.min_movie_year_1c);
        this->min_movie_year_1d = std::min(this->min_movie_year_1d, r.min_movie_year_1d);

        this->count_production_note_1a += r.count_production_note_1a;
        this->count_production_note_1b += r.count_production_note_1b;
        this->count_production_note_1c += r.count_production_note_1c;
        this->count_production_note_1d += r.count_production_note_1d;

        return *this;
    }

    RingJobs1 operator*(const RingJobs1 &other)
    {
        return RingJobs1(
            this->count_movie_title_1a * other.count_movie_title_1a,
            this->count_movie_title_1b * other.count_movie_title_1b,
            this->count_movie_title_1c * other.count_movie_title_1c,
            this->count_movie_title_1d * other.count_movie_title_1d,

            this->min_movie_year_1a == std::numeric_limits<int>::max() ? other.min_movie_year_1a : this->min_movie_year_1a,
            this->min_movie_year_1b == std::numeric_limits<int>::max() ? other.min_movie_year_1b : this->min_movie_year_1b,
            this->min_movie_year_1c == std::numeric_limits<int>::max() ? other.min_movie_year_1c : this->min_movie_year_1c,
            this->min_movie_year_1d == std::numeric_limits<int>::max() ? other.min_movie_year_1d : this->min_movie_year_1d,

            this->count_production_note_1a * other.count_production_note_1a,
            this->count_production_note_1b * other.count_production_note_1b,
            this->count_production_note_1c * other.count_production_note_1c,
            this->count_production_note_1d * other.count_production_note_1d);
    }

    // the multiplicity doesn't matter here
    RingJobs1 operator*(long int alpha) const
    {
        return RingJobs1(
            this->count_movie_title_1a * alpha,
            this->count_movie_title_1b * alpha,
            this->count_movie_title_1c * alpha,
            this->count_movie_title_1d * alpha,

            this->min_movie_year_1a,
            this->min_movie_year_1b,
            this->min_movie_year_1c,
            this->min_movie_year_1d,

            this->count_production_note_1a * alpha,
            this->count_production_note_1b * alpha,
            this->count_production_note_1c * alpha,
            this->count_production_note_1d * alpha);
    }

    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) const
    {
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, count_movie_title_1a);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, count_movie_title_1b);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, count_movie_title_1c);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, count_movie_title_1d);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, min_movie_year_1a);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, min_movie_year_1b);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, min_movie_year_1c);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, min_movie_year_1d);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, count_production_note_1a);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, count_production_note_1b);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, count_production_note_1c);
        ar << ELEM_SEPARATOR;
        DBT_SERIALIZATION_NVP(ar, count_production_note_1d);
    }
};

RingJobs1 operator*(long int alpha, const RingJobs1 &r)
{
    return RingJobs1(
        alpha * r.count_movie_title_1a,
        alpha * r.count_movie_title_1b,
        alpha * r.count_movie_title_1c,
        alpha * r.count_movie_title_1d,

        r.min_movie_year_1a,
        r.min_movie_year_1b,
        r.min_movie_year_1c,
        r.min_movie_year_1d,

        alpha * r.count_production_note_1a,
        alpha * r.count_production_note_1b,
        alpha * r.count_production_note_1c,
        alpha * r.count_production_note_1d);
}

// explicit RingJobs1() : count_movie_title_1a(0), count_movie_title_1b(0), count_movie_title_1c(0), count_movie_title_1d(0), min_movie_year_1a(std::numeric_limits<int>::max()), min_movie_year_1b(std::numeric_limits<int>::max()), min_movie_year_1c(std::numeric_limits<int>::max()), min_movie_year_1d(std::numeric_limits<int>::max()), count_production_note_1a(0), count_production_note_1b(0), count_production_note_1c(0), count_production_note_1d(0) {}
RingJobs1 Ulifttitles(int movie_year)
{
    bool cond_1a = true; // 1a has no condition on movie_year
    bool cond_1b = movie_year >= 2005 && movie_year <= 2010;
    bool cond_1c = movie_year > 2010;
    bool cond_1d = movie_year > 2000;

    int movie_year_prime = movie_year == -1 ? std::numeric_limits<int>::max() : movie_year;

    return RingJobs1(
        cond_1a ? 1 : 0,
        cond_1b ? 1 : 0,
        cond_1c ? 1 : 0,
        cond_1d ? 1 : 0,
        cond_1a ? movie_year_prime : std::numeric_limits<int>::max(),
        cond_1b ? movie_year_prime : std::numeric_limits<int>::max(),
        cond_1c ? movie_year_prime : std::numeric_limits<int>::max(),
        cond_1d ? movie_year_prime : std::numeric_limits<int>::max(),
        cond_1a ? 1 : 0,
        cond_1b ? 1 : 0,
        cond_1c ? 1 : 0,
        cond_1d ? 1 : 0);
}

RingJobs1 Uliftmoviecompanies(const STRING_TYPE &production_note)
{
    bool is_null = production_note == "-1";

    bool cond_1 = !is_null && production_note.find("(as Metro-Goldwyn-Mayer Pictures)") == std::string::npos;
    bool cond_2 = !is_null && production_note.find("(co-production)") != std::string::npos;
    bool cond_3 = !is_null && production_note.find("(presents)") != std::string::npos;

    bool cond_1a = cond_1 && (cond_2 || cond_3);
    bool cond_1b = cond_1;
    bool cond_1c = cond_1 && cond_2;
    bool cond_1d = cond_1; 

    return RingJobs1(
        cond_1a ? 1 : 0,
        cond_1b ? 1 : 0,
        cond_1c ? 1 : 0,
        cond_1d ? 1 : 0,

        cond_1a ? std::numeric_limits<int>::max() : -1,
        cond_1b ? std::numeric_limits<int>::max() : -1,
        cond_1c ? std::numeric_limits<int>::max() : -1,
        cond_1d ? std::numeric_limits<int>::max() : -1,

        cond_1a ? 1 : 0,
        cond_1b ? 1 : 0,
        cond_1c ? 1 : 0,
        cond_1d ? 1 : 0);


}

#endif /* RINGJOBS1_HPP */