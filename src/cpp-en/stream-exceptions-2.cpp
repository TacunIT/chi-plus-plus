/**
 * @file src/stream-exceptions-2.cpp
 * Example program for handling exceptions.
 */

#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{
    ifstream text;

    try {

        text.exceptions ( ios_base::failbit );
        text.open("nonexistentfile.txt");
        text.close();

    } catch(ios_base::failure e) {

        cerr << "Runtime error" << endl;

    }

    return 0;
}
