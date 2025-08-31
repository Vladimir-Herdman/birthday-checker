#ifndef BIRTHDAYCHECKER_DATES_H
#define BIRTHDAYCHECKER_DATES_H

#include <stddef.h>
#include <time.h>
#include <string.h>

struct Months {
    const char** month[12];
};
const char** get_month(const struct Months* m, const size_t idx);

extern const struct Months months;

struct Birthday {
    char date[19];
    char* names;
    time_t diff_time;
};

extern const char* lookup_num_str[10];

#endif //BIRTHDAYCHECKER_DATES_H
