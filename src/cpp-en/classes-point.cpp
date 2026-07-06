/**
 * @file classes-point.cpp
 * Access to the class's member data.
 */

using namespace std;

class Point
{
public:

    /** Declares the class's member data */
    int _x, _y;

    /**
     *  Functions internal to the class access
     *  member data with ordinary syntax.
     */
    Point(int x, int y) {
        _x = x;
        _y = y;
    }
} ;

int main(int argc, char** argv)
{
    /** Creates an object of class Point */
    Point p(5,6);

    /** Assigns the class instance to the pointer ptr */
    Point *ptr = &p ;

    /**
     *  Functions external to the class access
     *  member data through selection operators.
     */
    p._x    = 3 ;       // assigns a value through the object
    ptr->_y = 2 ;       // assigns a value through the pointer

    //...
}
