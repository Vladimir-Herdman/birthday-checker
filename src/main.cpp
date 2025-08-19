/*
 * From here, edit dates.hpp to add birthdays
 */

#include <ctime>
#include <iostream>

#include "dates.hpp"

#define SCI(arg) static_cast<int>(arg)
#define DE(arg) static_cast<int>(dates::arg)

int main() {
    using namespace std;

    time_t cur_ts = time(NULL);
    const tm cur_dt = (*localtime(&cur_ts));
    const time_t cur_day = cur_dt.tm_yday; //0-365, 0 is january 1st
    const int cur_year = cur_dt.tm_year;
    cout << cur_year;

    bool birthday_today = false;
    cout << months::at(1)[0];

    char buffer[50];
    strftime(buffer, 50, "%B %e, %Y", &cur_dt);
    cout << buffer;

    cout << months::january[DE(JAN_1)];

    return 0;
}

#undef SCI
#undef DE
