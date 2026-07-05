/**
 * @file memory-dynamic.cpp
 * Dynamic memory management.
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    /**
    * At this point it should check that the strings exist..
    */

    /** Reads the length of the two strings */
    size_t len1 = strlen(argv[1]);
    size_t len2 = strlen(argv[2]);

    /**
     * Allocates a memory area as large as the two
     * strings plus one space character and one
     * terminator character.
     */
    size_t length = len1 + len2 + 2;
    char* str = new char[length];

    /** Copies the strings into the memory area */
    sprintf(str, "%s %s", argv[1], argv[2]);

    /**
     * Shows the address of the memory area,
     * its size, and its content
     */
    cout << (void*)str << endl;
    cout << length     << endl;
    cout << str         << endl;

    /** Frees the allocated memory */
    delete[] str;

    return 0;
}
