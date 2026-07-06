/**
 * @file src/stream-exceptions-3.cpp
 * Example program for handling exceptions.
 */

#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{
    ifstream text;

    try {

        /** Checks that the name of the file to open exists */
        if(argc < 2)
            throw "Missing file name";

        text.exceptions ( ios_base::failbit );
        text.open(argv[1]);
        text.close();

    } catch(ios_base::failure e) {

        cerr << "Runtime error" << endl;

    } catch(char const* msg) {

        cerr << msg << endl;
    }

    return 0;
}
