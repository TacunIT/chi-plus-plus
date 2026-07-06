/**
 * @file src/stream-eof.cpp
 * Handling file I/O with streams.
 */

#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{
    ifstream text;
    int      n;

    /** opens the file for reading */
    text.open(argv[1]);

    /** Checks that the file is open */
    if(text.is_open()) {

        /** Uses eof to control the loop */
        while(!text.eof()) {

            /** Reads a number from the file */
            text >> n;

            /** Writes it to the screen */
            cout << n << endl;
        }

    }

    /** Closes the input file */
    text.close();

    return 0;
}
