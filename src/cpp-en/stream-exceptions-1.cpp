/**
 * @file src/stream-exceptions-1.cpp
 * Example program for handling exceptions.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    ifstream text;

    /**
    *   Makes it so an exception is thrown
    *   if there's an error handling the file.
    */
    text.exceptions ( ios_base::failbit );

    /** This instruction will throw an exception */
    text.open("nonexistentfile.txt");

    text.close();

    return 0;
}
