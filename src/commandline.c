#include "commandline.h"

#include <stdlib.h>
#include <stdio.h>

#if defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#endif

static enum Result usage() {
    printf("Usage: vh_bday [OPTION]\n");
    printf("  -h\tdisplay help text\n");
    printf("  -b\tHow many sequential dates to check for upcoming birthdays\n");
    printf("  -l\tprint in list format starting from today\n");
    return DO_NOTHING;
}

//parse command line arguments and change config as a result
enum Result commandLineArguments(const int argc, char* const argv[], int* bdays) {
#if defined(__unix__) || defined(__APPLE__)
    int opt;
    enum Result result = NO_CHANGES;
    while ((opt = getopt(argc, argv, ":hb:l")) != -1) {
        switch (opt) {
            case 'h': {//help
                return usage();
            }
            case 'b': {
                *bdays = atoi(optarg);
                break;
            }
            case 'l': {
                result = LIST_PRINT;
                break;
            }
            case ':': {
                fprintf(stderr, "Option -%c requires an argument\n", (char)optopt);
                return DO_NOTHING;
            }
            case '?': {
                fprintf(stderr, "Invalid command line argument passed: -%d\n", opt);
                return DO_NOTHING;
            }
        }
    }
#else
    for (int i = 1; i < argc; i++) {
        const char arg = argv[i][1];
        switch (arg) {
            case 'h': usage(); break; 
            case 'd': CONFIG::OPTIONS.dry_run = true; break; //defaults, so no config reading
            case 'v': CONFIG::OPTIONS.verbose = true; break; //verbose
            default: unknownOption(arg);
        }
    }
#endif
    return result;
}
