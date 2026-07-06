/**
 * @file src/polymorphism-functor-stl.cpp
 * Example of STL function objects.
 */

#include <iostream>
#include <functional>

using namespace std;

int main ()
{
    int a = 12;
    int b = 4;

    /** Declaration of functor objects */
    plus<int>       p;
    minus<int>      m;
    multiplies<int> x;
    divides<int>    d;
    modulus<int>    o;

    /** Using the objects as if they were functions */
    cout << "plus: "       << p(a,b) << endl;
    cout << "minus: "      << m(a,b) << endl;
    cout << "multiplies: " << x(a,b) << endl;
    cout << "divides: "    << d(a,b) << endl;
    cout << "modulus: "    << o(a,5) << endl;

    /** "runs" the object o with new parameters */
    cout << "modulus: "    << o(a,5) << endl;

    return 0;
}
