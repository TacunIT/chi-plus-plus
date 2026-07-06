/**
 * @file planets-main.cpp
 * Main function for the Planet management program.
 */

#include <iostream>
#include "planets.h"

using namespace std;

int main(int argc, char** argv)
{
    int p = POS_MERCURY;

    /** Lists all the Planets of the Solar System */
    for ( ; ; ) {
        cout << p << ": ";
        /** If it encounters an error, it stops */
        if(!showPlanet( ++p )) break;
        cout << endl;
    }

    cout << endl;

    return 0;
}
