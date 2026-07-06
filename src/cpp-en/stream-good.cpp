/**
 * @file src/stream-good.cpp
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

    /**
    *   The loop repeats until
    *   an error occurs
    */
    while(text.good()) {

        /** Reads a number from the file */
        text >> n;

        /** Stops if the file has ended */
        if(text.eof()) break;

        /** Otherwise, writes the number */
        cout << n << endl;
    }

    /** Closes the input file */
    text.close();

    return 0;
}
