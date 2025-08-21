#ifndef BIRTHDAYCHECKER_DATES_H
#define BIRTHDAYCHECKER_DATES_H

#include <string>

namespace dates {
    struct Months {
        const std::string* jan;
        const std::string* feb;
        const std::string* mar;
        const std::string* apr;
        const std::string* may;
        const std::string* jun;
        const std::string* jul;
        const std::string* aug;
        const std::string* sep;
        const std::string* oct;
        const std::string* nov;
        const std::string* dec;

        const std::string* m_map[12] = {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
        const std::string* operator[](const size_t idx) const {return m_map[idx];}
    };
    extern const Months months;

    struct Birthday {
        std::string date;
        std::string names;
    };

}

#endif //BIRTHDAYCHECKER_DATES_H
