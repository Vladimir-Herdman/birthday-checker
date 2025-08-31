#include "dates.h"

// go one day under actual date as arrays 0-indexed
static const char* january[31] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* february[29] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* march[31] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* april[30] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* may[31] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* june[30] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* july[31] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* august[31] = {
    [1] = "test name, test two",
    [4] = "another test, and here",
    [30] = "self,John Stamos"
};
static const char* september[30] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* october[31] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* november[30] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};
static const char* december[31] = {
    [1] = "test name, test two",
    [4] = "another test, and here"
};

const struct Months months = {
    .month = {
        january, february, march, april, may, june, july, august, september, october, november, december
    }
};

const char** get_month(const struct Months* m, const size_t idx) {
    return m->month[idx];
}

const char* lookup_num_str[10] = {
    "", "", "two", "three", "four", "five", "six", "seven", "eight", "nine" 
};

