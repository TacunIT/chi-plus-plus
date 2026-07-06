/**
 * @file planets-while-string.cpp
 * Handling Planets with string values.
 */

#include <iostream>
#include "planets.h"

using namespace std;

int main(int argc, char** argv)
{
    int    p  = POS_MERCURY;
    string name;

    /**
     * Separates data processing from its
     * possible display
     */
    while (!(name = planetName(p)).empty()) {
        cout << p++ << ": " << name << endl;
    }

    return 0;
}
