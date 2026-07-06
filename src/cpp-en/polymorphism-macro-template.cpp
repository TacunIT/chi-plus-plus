/**
 * @file src/polymorphism-macro-template.cpp
 * Template functions and precompiler macros.
 */

#include <iostream>

using namespace std;

/**
*  Definition of a precompiler macro
*  instruction: no type checking.
*/
#define GREATER(a,b) ((a > b) ? a : b)

/**
*  Definition of a template function
*  that returns the greater of two parameters.
*/
template<class T>
T greater (T x, T y) {
    return (x > y) ? x : y;
}

int main ()
{
    int    a = 10;
    short  b = 0;
    double d = 3.123456789;

    /** Using the macro */
    cout << GREATER(9,12)     << endl;
    cout << GREATER(0.4, 0.7) << endl;
    cout << GREATER('a', 'z') << endl;

    /**
    *  The same function can be used
    *  with different data types:
    */
    cout << greater<int>   (  9,  12) << endl;
    cout << greater<double>(0.4, 1.2) << endl;
    cout << greater<char>  ('a', 'z') << endl;

    /** Error: compares a character with a double */
    cout << GREATER('a', d) << endl;

    /**
    *   Error: the compiler doesn't know which
    *   of the two data types to use.
    */
    cout << greater(a, b) << endl;

    return 0;
}
