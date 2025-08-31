/*
 * From here, edit src/dates.cpp to add birthdays
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "commandline.h"
#include "dates.h"


static inline void add_day(struct tm* potential_dt) {
    potential_dt->tm_mday += 1;
    mktime(potential_dt);
}

void print_today_bday(const struct tm* cur_dt) {
    struct Birthday bday_today;
    const time_t cur_month = cur_dt->tm_mon; //0 indexed, so 0-11
    const time_t cur_day = cur_dt->tm_mday; //1 indexed, so 1-31 for month day

    printf("Today:\n");

    const char* og_name = get_month(&months, cur_month)[cur_day-1];
    if (og_name != NULL) {
        const size_t len = strlen(og_name) + 1; //+1 is for null terminator

        strftime(bday_today.date, sizeof(bday_today.date), "%B %d, %Y", cur_dt);

        char* copy = malloc(len);
        strcpy(copy, og_name);

        bday_today.names = copy;
        const int name_len = strlen(bday_today.names);

        if (!(bday_today.names[0] == '\0' || bday_today.date[0] == '\0')) {
            if (strstr(bday_today.names, "self") != NULL) {
                if (name_len >= 5) {
                    memmove(bday_today.names, bday_today.names+5, name_len-4);
                } else {
                    bday_today.names[0] = '\0';
                }

                printf("  * Happy Birthday Today!!!\n");
                printf("  * Other's that share today - %s\n\n", (bday_today.names[0] == '\0' ? "No one else" : bday_today.names));
            } else {
                printf("  * %s - %s\n\n", bday_today.date, bday_today.names);
            }
        } else {printf("  * No birthdays today\n\n");}

        free(copy);
    } else {printf("  * No birthdays today\n\n");}
}

void print_nearest_bdays(struct tm cur_dt, const int how_many_bdays, const int go_back) {
    if (how_many_bdays <= 0) {return;}

    struct tm potential_dt = cur_dt;
    struct Birthday* next_three = malloc(how_many_bdays * sizeof(*next_three));

    int birthday_counter = 0;

    if (go_back != 0) {potential_dt.tm_mday -= go_back; mktime(&potential_dt);}

    char number_str[6];
    const char* bdays_num = (how_many_bdays < 10
        ? lookup_num_str[how_many_bdays]
        : (sprintf(number_str, "%d", how_many_bdays), number_str) //comma trick to return after writing to number_str buffer
    );
    printf("Next %s%s:\n",
         bdays_num,
         (how_many_bdays > 1 ? " birthdays" : "birthday")
    );
    for (int i = 0; i < 365; i++) {
        add_day(&potential_dt);
        const int pot_month = potential_dt.tm_mon; //0 indexed, so 0-11
        const int pot_mday = potential_dt.tm_mday; //1 indexed, so 1-31 for month day
        const char* pot_birth_name = get_month(&months, pot_month)[pot_mday-1];

        if (pot_birth_name != NULL && !(pot_birth_name[0] == '\0')) {
            strftime(next_three[birthday_counter].date, sizeof(next_three[birthday_counter].date), "%B %d, %Y", &potential_dt);

            next_three[birthday_counter].names = malloc(strlen(pot_birth_name) + 1);

            strcpy(next_three[birthday_counter].names, pot_birth_name);
            next_three[birthday_counter].diff_time = difftime(mktime(&potential_dt), mktime(&cur_dt));
            birthday_counter++;
        }

        if (birthday_counter == how_many_bdays) {break;}
    }

    //out here, check for birthday values and print them out with their dates
    for (int i = 0; i < how_many_bdays; i++) {
        struct Birthday* group = &next_three[i];
        if (!(group->names[0] == '\0' || group->date[0] == '\0')) {
            const int days_later = group->diff_time / 86400; //seconds in a day
            if (days_later == 0) {
                printf("  * %s - %s - Today!\n", group->date, group->names);
            } else {
                printf("  * %s - %s - in %d %s\n", group->date, group->names, days_later, (days_later > 1 ? " days" : " day"));
            }
        }
        free(next_three[i].names);
    }

    free(next_three); //cleanup dynamic array from beginning
}

int main(const int argc, char* const argv[]) {
    int bdays_to_get = 3;
    const enum Result result = commandLineArguments(argc, argv, &bdays_to_get);

    time_t cur_ts = time(NULL);
    const struct tm cur_dt = (*localtime(&cur_ts));

    switch (result) {
        case NO_CHANGES: {
            print_today_bday(&cur_dt);
            print_nearest_bdays(cur_dt, bdays_to_get, 0);
            break;
        }
        case LIST_PRINT: {
            print_nearest_bdays(cur_dt, bdays_to_get, 1);
        }
        case DO_NOTHING: {
            break;
        }
    }

    return 0;
}
