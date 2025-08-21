/*
 * From here, edit src/dates.cpp to add birthdays
 */
#include <ctime>
#include <iostream>

#include "dates.hpp"

using namespace std;


inline void add_day(tm& potential_dt) {potential_dt.tm_mday += 1; mktime(&potential_dt);}

void print_today_bday(const tm& cur_dt) {
    dates::Birthday bday_today;
    const time_t cur_month = cur_dt.tm_mon; //0 indexed, so 0-11
    const time_t cur_day = cur_dt.tm_mday; //1 indexed, so 1-31 for month day

    char buffer[18];
    strftime(buffer, 18, "%B %e, %Y", &cur_dt);

    bday_today.names = dates::months[cur_month][cur_day-1];
    bday_today.date = buffer;

    if (!(bday_today.names.empty() || bday_today.date.empty())) {
        cout << bday_today.date << " - " << bday_today.names << '\n';
    } else {cout << "No birthdays today\n";}
}

void print_nearest_bdays(tm potential_dt) {
    dates::Birthday next_three[3];
    int birthday_counter = 0;

    for (int i = 0; i < 365; i++) {
        add_day(potential_dt);
        const int pot_month = potential_dt.tm_mon; //0 indexed, so 0-11
        const int pot_mday = potential_dt.tm_mday; //1 indexed, so 1-31 for month day
        const string pot_birth_name = dates::months[pot_month][pot_mday-1];

        if (!pot_birth_name.empty()) {
            char buffer[18];
            strftime(buffer, 18, "%B %e, %Y", &potential_dt);

            next_three[birthday_counter].names = pot_birth_name;
            next_three[birthday_counter].date = buffer;
            birthday_counter++;
        }

        if (birthday_counter == 2) {break;}
    }

    // out here, check for birthday values and print them out with their dates
    for (int i = 0; i < 2; i++) {
        dates::Birthday& group = next_three[i];
        if (!(group.names.empty() || group.date.empty())) {
            cout << group.date << " - " << group.names << '\n';
       }
   }
}

int main() {
    //TODO: add command line to see how far into future to check for bdays (so pass 4 to get next 4 bdays)
    time_t cur_ts = time(NULL);
    const tm cur_dt = (*localtime(&cur_ts));

    print_today_bday(cur_dt);
    print_nearest_bdays(cur_dt);

    return 0;
}
