/**
 * @file planets-while-error-1.cpp
 * Handling Planets with an obvious error.
 */

#include <iostream>
#include "planets.h"

using namespace std;

int main(int argc, char** argv)
{
    int    p  = POS_MERCURY;
    string name;

    while (!(name = planetName(p)).empty()) {
        cout << name << endl;
    }

    return 0;
}
