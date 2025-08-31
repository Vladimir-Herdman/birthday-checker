#ifndef TERMINALCHESS_CROSSPLATFORM_COMMANDLINE_H
#define TERMINALCHESS_CROSSPLATFORM_COMMANDLINE_H

enum Result : int {
    NO_CHANGES, LIST_PRINT, DO_NOTHING
};

enum Result commandLineArguments(const int argc, char* const argv[], int* bdays);

#endif //TERMINALCHESS_CROSSPLATFORM_COMMANDLINE_H
