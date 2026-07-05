/**
 * @file memory-static.cpp
 * Static memory management.
 */

#include <iostream>

/** Defines the size of the string */
#define STRING_SIZE 200

using namespace std;

int main(int argc, char** argv)
{
    /** Reserves a space of 200 characters */
    char str[STRING_SIZE];

    /**
    * At this point it should check that the strings exist
    * and that, combined, they're shorter than 200 characters..
    */

    /** Copies the strings into the memory area */
    sprintf(str, "%s %s", argv[1], argv[2]);

    /** Prints the string to the screen */
    cout << str << endl;

    return 0;
}
