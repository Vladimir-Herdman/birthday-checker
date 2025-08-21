#include "commandline.hpp"

#include <cstdlib>
#include <iostream>

#if defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#endif

using namespace std;

namespace {
    Result usage() {
        cout << "Usage: vh_bday [OPTION]\n";
        cout << "  -h\tdisplay help text\n";
        cout << "  -b\tHow many sequential dates to check for upcoming birthdays\n";
        cout << "  -l\tprint in list format starting from today\n";
        return Result::DO_NOTHING;
    }
}

//parse command line arguments and change config as a result
Result commandLineArguments(const int argc, char* const argv[], int& bdays) {
#if defined(__unix__) || defined(__APPLE__)
    int opt;
    Result result = Result::NO_CHANGES;
    while ((opt = getopt(argc, argv, ":hb:l")) != -1) {
        switch (opt) {
            case 'h': {//help
                return usage();
            }
            case 'b': {
                bdays = atoi(optarg);
                break;
            }
            case 'l': {
                result = Result::LIST_PRINT;
                break;
            }
            case ':': {
                cerr << "Option -" << (char)optopt << " requires an argument\n";
                return Result::DO_NOTHING;
            }
            case '?': {
                cerr << "Invalid command line argument passed: -" << opt << '\n';
                return Result::DO_NOTHING;
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
