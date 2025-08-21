/*
 * From here, edit dates.hpp to add birthdays
 */

#include <ctime>
#include <iostream>

#include "dates.hpp"

#define SCI(arg) static_cast<int>(arg)

using namespace std;

inline void add_day(tm& potential_dt) {potential_dt.tm_mday += 1; mktime(&potential_dt);}

void check_print_today(const tm& cur_dt) {
    const time_t cur_month = cur_dt.tm_mon;
    const time_t cur_day = cur_dt.tm_yday; //0-365, 0 is january 1st
    const int cur_year = cur_dt.tm_year;
    cout << cur_month << endl;
    cout << cur_dt.tm_yday << endl;
}

void print_nearest_three(tm potential_dt) {
    string next_three[3] = {"", "", ""};
    int birthday_counter = 0;

    for (int i = 0; i < 365; i++) {
        add_day(potential_dt);
        const int pot_month = potential_dt.tm_mon;
        const int pot_mday = potential_dt.tm_mday;
        const string pot_birth_name = months[pot_month][pot_mday];

        if (!pot_birth_name.empty()) {
            next_three[birthday_counter] = pot_birth_name;
            birthday_counter++;
        }

        if (birthday_counter == 2) {break;}
    }

    // out here, check for birthday values and print them out with their dates
}

int main() {
    char buffer[50];
    char buffer2[50];
    //strftime(buffer, 50, "%B %e, %Y", &cur_dt);
    //strftime(buffer2, 50, "%B %e, %Y", &potential_dt);
    cout << buffer << '\n';
    cout << buffer2 << '\n';

    //cout << months.jan[DE(JAN_1)];

    //check current day for birthday
    time_t cur_ts = time(NULL);
    const tm cur_dt = (*localtime(&cur_ts));
    check_print_today(cur_dt);

    //check nearest three birthdays that isn't today
    //tm potential_dt = cur_dt;
    print_nearest_three(cur_dt);

    return 0;
}

#undef SCI
