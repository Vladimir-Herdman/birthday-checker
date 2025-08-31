#ifndef BIRTHDAYCHECKER_DATES_H
#define BIRTHDAYCHECKER_DATES_H

#include <ctime>
#include <string>

namespace dates {
    struct Months {
        const char* const* m_map[12];
        const char* const* operator[](const size_t idx) const {return m_map[idx];}
    };
    extern const Months months;

    struct Birthday {
        std::string date;
        std::string names;
        time_t diff_time;
    };

    constexpr const char* lookup_num_str[10] = {
        "", "", "two", "three", "four", "five", "six", "seven", "eight", "nine" 
    };
}

#endif //BIRTHDAYCHECKER_DATES_H
