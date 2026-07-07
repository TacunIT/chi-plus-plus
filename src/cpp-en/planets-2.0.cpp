/**
 * @file planets.cpp
 * @version 2.0
 * Functions for handling Planets.
 */

#include <iostream>
#include "planets.h"

/**
 *  showPlanet
 *  Displays the name of a planet, given its position.
 *  @param  int  planet Position of the planet.
 *  @return bool exists  true if the planet exists.
 */
bool showPlanet(int planet)
{
    bool exists = true;

    switch( planet ) {
        case POS_ERROR:
            cout << "Invalid value";
            break;
        case POS_MERCURY:
            cout << "Mercury";
            break;
        case POS_VENUS:
            cout << "Venus";
            break;
        case POS_EARTH:
            cout << "Earth";
            break;
        case POS_MARS:
            cout << "Mars";
            break;
        case POS_JUPITER:
            cout << "Jupiter";
            break;
        case POS_SATURN:
            cout << "Saturn";
            break;
        case POS_URANUS:
            cout << "Uranus";
            break;
        case POS_NEPTUNE:
            cout << "Neptune";
            break;
        case POS_PLUTO:
            cout << "Pluto";
            break;
        default:
            exists = false;
            cout << "Enter a value from: "
                 << POS_MERCURY
                 << " to "
                 << POS_PLUTO;
    }

    return exists;
}

/**
 *  planetName
 *  Returns the name of a planet, given its position.
 *  @param  int    position Position of the planet.
 *  @return string name     Name of the planet, or null on error.
 */
string planetName(int position)
{
    string name;

    /**
     * This function only handles the existing cases
     * and lets the calling function handle any
     * errors.
     */
    switch( position ) {
        case POS_MERCURY:
            name = "Mercury";
            break;
        case POS_VENUS:
            name = "Venus";
            break;
        case POS_EARTH:
            name = "Earth";
            break;
        case POS_MARS:
            name = "Mars";
            break;
        case POS_JUPITER:
            name = "Jupiter";
            break;
        case POS_SATURN:
            name = "Saturn";
            break;
        case POS_URANUS:
            name = "Uranus";
            break;
        case POS_NEPTUNE:
            name = "Neptune";
            break;
        case POS_PLUTO:
            name = "Pluto";
            break;
    }

    return name;
}
