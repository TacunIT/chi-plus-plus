/**
 * @file src/polymorphism-class-template.cpp
 * Example of a class template.
 */

#include <iostream>

using namespace std;

/**
*   Defines a class that handles pairs
*   of coordinates.
*/
template<class T>
class Coord {
private:
    /** Member data with variable type */
    T _x, _y;
public:
    /** Constructor with variable parameter type */
    Coord(const T x, const T y)
    : _x(x), _y(y) {
    }
    friend ostream& operator << (ostream& o, const Coord& c) {
        o << c._x << ',' << c._y ;
        return o;
    }
};

int main ()
{
    /** Instance with geographic coordinates */
    Coord<double> obelisk(41.903219, 12.458157);

    /** Instance with screen coordinates */
    Coord<int>    pixel(821, 134);

    cout << "Obelisk:" << obelisk << endl;
    cout << "Pixel:   " << pixel    << endl;

    return 0;
}
