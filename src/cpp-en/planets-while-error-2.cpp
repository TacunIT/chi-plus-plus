/**
 * @file planets-while-error-2.cpp
 * Handling Planets with an error in the while loop
 */

#include <iostream>
#include "planets.h"

using namespace std;

int main(int argc, char** argv)
{
    int    p  = POS_MERCURY;
    string name;

    while (!(name = planetName(++p)).empty()) {
        cout << name << endl;
    }

    return 0;
}
