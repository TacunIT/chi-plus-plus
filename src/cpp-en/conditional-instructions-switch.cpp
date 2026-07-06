#include <iostream>
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

int main(int argc, char** argv)
{
    int planet;

    /**
     * Reads the input parameters.
     * If there are any, tries to convert the first parameter
     * into an integer. If the parameter isn't an integer, the
     * atoi function returns 0.
     */
    if(argc > 1) {
        planet = atoi(argv[1]);
    } else {
        planet = POS_NONE;
    }

    /** Handles the possible cases */
    switch( planet ) {
        case POS_ERROR:   cout << "Invalid value";
            break;
        case POS_MERCURY: cout << "Mercury";
            break;
        case POS_VENUS:   cout << "Venus";
            break;
        case POS_EARTH:   cout << "Earth";
            break;
        case POS_MARS:    cout << "Mars";
            break;
        case POS_JUPITER: cout << "Jupiter";
            break;
        case POS_SATURN:  cout << "Saturn";
            break;
        case POS_URANUS:  cout << "Uranus";
            break;
        case POS_NEPTUNE: cout << "Neptune";
            break;
        case POS_PLUTO:   cout << "Pluto";
            break;
        default:
            cout << "Enter a value from: "
                 << POS_MERCURY
                 << " to "
                 << POS_PLUTO;
    }

    cout << endl;

    return 0;
}
