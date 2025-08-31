# birthday_checker
A command-line tool to take a list of birthdays and names, and print upcoming
ones up to a user-set amount, or just check today's.  Created using C++ as the
main language with bash scripts to aid the installation process.  A C version
exists for those who prefer.

Generally designed for use on a UNIX-based system, like a MAC or Linux system,
compilation works on Windows, but you'll have to figure out the pathing from
there :)

Compiled mainly using clang, designated initializers are used in the file
where we store birthdays.  May require some recoding in the array section
to get working for g++, or just go to the C branch to compile there using
clang or gcc.  To quickly change the compiler, just edit the Makefile variable
`CXX` to what you use.
## Branches
While mainly here a C++ project, even for such a small one, I wanted to see if
there would be any final result differences if it were instead compiled from C,
and not C++.  Overall, I found the final C++ binary, on my machine, to be 36K,
while the pure C binary came out to be 52K.  While local to my machine, still
interesting to see some difference, though it could be from being more proficient
in C++ as opposed to C, you can judge that if you want to take a look.

The more_C branch I was just checking if there's a difference in between with using
C in C++, though I found nothing to note.
## CLI Options
* -h -> Will print the usage help info
* -b [NUMBER] -> how many birthdays to look ahead, so like get the next 4 birthdays
* -l -> list format, don't print a separate today section, just include it in the list

## Adding to the birthday list
To add birthdays, go to the `src/dates.cpp` file and add names to the named
month arrays for each birthday, so for a birthday on August 21st each year,
go to the `august` array and add the name to the **20th** array index, as the
arrays are zero-indexed, so go one under the actual day to have the date show
up correctly in printing.

In C++ using clang++ with extensions:
```cpp
constexpr const char* august[31] = {
  [7] = "John Hopkins", //birthday on August 8th each year
  [12] = "Jonas King", //birthday on August 13th each year
  ...
}
```
## Installation Scripts
If you need help making the binary available to your system path, take a peek
at `scripts/install.sh`.  You don't have to use it, it just alleviates installation
for me as I use `$HOME/.local/bin` for my own binaries, but if you understand the
process or have somewhere else you want to store it, you can edit the `globals.sh`
file variable `INSTALL_DIR` to set where you want it installed.

You can also change `BINARY_NAME` to set what you want the final binary's name to be,
though you can also just grab it from the `bin/` directory and rename `main` from there
if you just compile using make and your compiler of choice.
## Example Use
Just for an example use from clone to set up:
```bash
git clone https://github.com/Vladimir-Herdman/birthday-checker
cd birthday-checker
```

From here, you can use the install script or just do it yourself as such:
```bash
./scripts/install.sh
```
OR
```bash
make
mv ./bin/main /{<wherever you store>}
```

Don't forget for wherever you put it, include that location in your system path
to then use it whenever!
### Example Output
```bash
./bin/main
Today:
  August 31, 2025 - Sam Clawson

Next three birthdays:
  * September 01, 2025 - Brooks Blakeley - in 1 day
  * September 17, 2025 - Zach Iles - in 17 days
  * September 21, 2025 - Owen Willoby - in 21 days
```
