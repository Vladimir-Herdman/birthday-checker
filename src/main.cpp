/*
 * From here, edit src/dates.cpp to add birthdays
 */
#include <ctime>
#include <stdio.h>

#include "commandline.hpp"
#include "dates.hpp"

using namespace std;


inline void add_day(tm& potential_dt) {potential_dt.tm_mday += 1; mktime(&potential_dt);}

void print_today_bday(const tm& cur_dt) {
    dates::Birthday bday_today;
    const time_t cur_month = cur_dt.tm_mon; //0 indexed, so 0-11
    const time_t cur_day = cur_dt.tm_mday; //1 indexed, so 1-31 for month day

    char buffer[19];
    strftime(buffer, 19, "%B %d, %Y", &cur_dt);

    const char* name_check = dates::months[cur_month][cur_day-1]; //empty in char* array is nullptr, so can't just assign to string
    bday_today.names = (name_check == nullptr ? "" : name_check);

    bday_today.date = buffer;
    const int name_len = bday_today.names.length();

    printf("Today:\n");
    if (!(bday_today.names.empty() || bday_today.date.empty())) {
        if (bday_today.names.contains("self")) {
            if (name_len >= 5) {bday_today.names.erase(0, 5);} else {bday_today.names.clear();}

            printf("  * Happy Birthday Today!!!\n  * Other's that share today - %s\n\n", (bday_today.names.empty() ? "No one else" : bday_today.names).c_str());
        } else {
            printf("  %s - %s\n\n", bday_today.date.c_str(), bday_today.names.c_str());
        }
    } else {printf("  No birthdays today\n\n");}
}

void print_nearest_bdays(tm cur_dt, const int how_many_bdays = 3, const int go_back = 0) {
    if (how_many_bdays <= 0) {return;}

    tm potential_dt = cur_dt;
    dates::Birthday* next_three = new dates::Birthday[how_many_bdays];
    int birthday_counter = 0;

    if (go_back != 0) {potential_dt.tm_mday -= go_back; mktime(&potential_dt);}

    printf("Next %s%s:\n",
         (how_many_bdays < 10 ? dates::lookup_num_str[how_many_bdays] : to_string(how_many_bdays)).c_str(),
         (how_many_bdays > 1 ? " birthdays" : "birthday"));
    for (int i = 0; i < 365; i++) {
        add_day(potential_dt);
        const int pot_month = potential_dt.tm_mon; //0 indexed, so 0-11
        const int pot_mday = potential_dt.tm_mday; //1 indexed, so 1-31 for month day

        const char* name_check = dates::months[pot_month][pot_mday-1]; //empty in char* array is nullptr, so can't just assign to string
        const string pot_birth_name = (name_check == nullptr ? "" : name_check);

        if (!pot_birth_name.empty()) {
            char buffer[19];
            strftime(buffer, 19, "%B %d, %Y", &potential_dt);

            next_three[birthday_counter].names = pot_birth_name;
            next_three[birthday_counter].date = buffer;
            next_three[birthday_counter].diff_time = difftime(mktime(&potential_dt), mktime(&cur_dt));
            birthday_counter++;
        }

        if (birthday_counter == how_many_bdays) {break;}
    }

    //out here, check for birthday values and print them out with their dates
    for (int i = 0; i < how_many_bdays; i++) {
        dates::Birthday& group = next_three[i];
        if (!(group.names.empty() || group.date.empty())) {
            const int days_later = group.diff_time / 86400; //seconds in a day
            if (days_later == 0) {
                printf("  * %s - %s - Today!\n", group.date.c_str(), group.names.c_str());
            } else {
                printf("  * %s - %s - in %d %s\n", group.date.c_str(), group.names.c_str(), days_later, (days_later > 1 ? "days" : "day"));
            }
        }
    }

    delete[] next_three; //cleanup dynamic array from beginning
}

int main(const int argc, char* const argv[]) {
    int bdays_to_get = 3;
    const Result result = commandLineArguments(argc, argv, bdays_to_get);

    time_t cur_ts = time(NULL);
    const tm cur_dt = (*localtime(&cur_ts));

    switch (result) {
        case Result::NO_CHANGES: {
            print_today_bday(cur_dt);
            print_nearest_bdays(cur_dt, bdays_to_get);
            break;
        }
        case Result::LIST_PRINT: {
            print_nearest_bdays(cur_dt, bdays_to_get, 1);
        }
        case Result::DO_NOTHING: {
            break;
        }
    }

    return 0;
}
