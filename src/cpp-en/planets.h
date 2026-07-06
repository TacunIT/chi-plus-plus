/**
 * @file planets.h
 * Constants and function for handling Planets.
 */

#ifndef _PLANETS
#define _PLANETS 1

using namespace std;

/** Declaration of constants */
#define POS_NONE     -1
#define POS_ERROR     0
#define POS_MERCURY   1
#define POS_VENUS     2
#define POS_EARTH     3
#define POS_MARS      4
#define POS_JUPITER   5
#define POS_SATURN    6
#define POS_URANUS    7
#define POS_NEPTUNE   8
#define POS_PLUTO     9

/** Declaration of functions */
bool showPlanet(int planet);
string planetName(int position);

#endif /* _PLANETS */
