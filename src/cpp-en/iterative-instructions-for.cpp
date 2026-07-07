/**
 * @file src/iterative-instructions-for.cpp
 * Example use of a for loop.
 */

#include <cstdlib>

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

using namespace std;

/**
 *  showPlanet
 *  Displays the name of a planet, given its position.
 *  @param  int  planet Position of the planet.
 *  @return bool exists  true if the planet exists.
 */
bool showPlanet(int planet )
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
 *  main
 *  Main function of the program, calls the
 *  showPlanet function passing it values from 1 to 9.
 */
int main(int argc, char** argv)
{
    int p = POS_NONE;

    /** Lists all the Planets of the Solar System */
    for ( p = POS_MERCURY; p <= POS_PLUTO; p++ ) {
        cout << p << ": ";
        showPlanet( p );
        cout << endl;
    }

    return 0;
}
