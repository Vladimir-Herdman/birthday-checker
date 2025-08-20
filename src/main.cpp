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
    tm potential_dt = cur_dt;
    potential_dt.tm_mday += 200;
    mktime(&potential_dt);
    const time_t cur_month = cur_dt.tm_mon;
    const time_t cur_day = cur_dt.tm_yday; //0-365, 0 is january 1st
    const int cur_year = cur_dt.tm_year;
    cout << cur_month << endl;
    cout << cur_dt.tm_yday << endl;
    cout << potential_dt.tm_yday << endl;

    char buffer[50];
    char buffer2[50];
    strftime(buffer, 50, "%B %e, %Y", &cur_dt);
    strftime(buffer2, 50, "%B %e, %Y", &potential_dt);
    cout << buffer << '\n';
    cout << buffer2 << '\n';

    cout << months.jan[DE(JAN_1)];

    return 0;
}

#undef SCI
#undef DE
