/*
 * From here, edit src/dates.cpp to add birthdays
 */
#include <ctime>
#include <iostream>

#include "commandline.hpp"
#include "dates.hpp"

using namespace std;


inline void add_day(tm& potential_dt) {potential_dt.tm_mday += 1; mktime(&potential_dt);}

void print_today_bday(const tm& cur_dt) {
    dates::Birthday bday_today;
    const time_t cur_month = cur_dt.tm_mon; //0 indexed, so 0-11
    const time_t cur_day = cur_dt.tm_mday; //1 indexed, so 1-31 for month day

    char buffer[19];
    strftime(buffer, 19, "%B %e, %Y", &cur_dt);

    bday_today.names = dates::months[cur_month][cur_day-1];
    bday_today.date = buffer;
    const int name_len = bday_today.names.length();

    cout << "Today:\n";
    if (!(bday_today.names.empty() || bday_today.date.empty())) {
        if (bday_today.names.contains("self")) {
            if (name_len >= 5) {bday_today.names.erase(0, 5);} else {bday_today.names.clear();}

            cout << "  * Happy Birthday Today!!!\n";
            cout << "  * Other's that share today - " << (bday_today.names.empty() ? "No one else\n\n" : bday_today.names+"\n\n");
        } else {
            cout << "  " << bday_today.date << " - " << bday_today.names << "\n\n";
        }
    } else {cout << "  No birthdays today\n\n";}
}

void print_nearest_bdays(tm cur_dt, const int how_many_bdays = 3, const int go_back = 0) {
    if (how_many_bdays <= 0) {return;}

    tm potential_dt = cur_dt;
    dates::Birthday* next_three = new dates::Birthday[how_many_bdays];
    int birthday_counter = 0;

    if (go_back != 0) {potential_dt.tm_mday -= go_back; mktime(&potential_dt);}

    cout << "Next "
         << (how_many_bdays < 10 ? dates::lookup_num_str[how_many_bdays] : to_string(how_many_bdays))
         << (how_many_bdays > 1 ? " birthdays" : "birthday") << ":\n";
    for (int i = 0; i < 365; i++) {
        add_day(potential_dt);
        const int pot_month = potential_dt.tm_mon; //0 indexed, so 0-11
        const int pot_mday = potential_dt.tm_mday; //1 indexed, so 1-31 for month day
        const string pot_birth_name = dates::months[pot_month][pot_mday-1];

        if (!pot_birth_name.empty()) {
            char buffer[19];
            strftime(buffer, 19, "%B %e, %Y", &potential_dt);

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
            cout << "  * " << group.date << " - " << group.names
                 << " - in " << days_later << (days_later > 1 ? " days" : " day") << '\n';
        }
    }

    delete[] next_three; //cleanup dynamic array from beginning
}

int main(const int argc, char* const argv[]) {
    //TODO: add command line to see how far into future to check for bdays (so pass 4 to get next 4 bdays)
    ios_base::sync_with_stdio(false);

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
