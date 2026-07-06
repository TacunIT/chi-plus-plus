/**
 * @file planets-while-bool.cpp
 * Handling Planets with a while instruction.
 */

#include <iostream>
#include "planets.h"

using namespace std;

int main(int argc, char** argv)
{
    int  p  = POS_MERCURY;

    /** Assigns a value to the control variable */
    bool ok = true;

    /** Repeats the action as long as the variable equals true */
    while (ok) {

        /** Shows the value of p and increments it */
        cout << p++ << ": ";

        /**
         * Shows the name of the planet and saves the outcome of the
         * function in the ok variable
         */
        ok = showPlanet(p);

        /** Adds the usual line break */
        cout << endl;
    }

    return 0;
}
