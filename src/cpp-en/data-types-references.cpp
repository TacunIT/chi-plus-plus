/**
 * @file data-types-references.cpp
 * Using references.
 */

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    /** Defines a variable of type int */
    int  v = 10;
    /** Defines a reference to the variable v */
    int& r = v;
    /** The values of v and r are identical because r is an alias of v */
    cout << "initial values: v=" << v << ", r=" << r << endl;
    /** Modifies the value of the variable r */
    r = 20;
    /** The value of v will change accordingly */
    cout << "final values:   v=" << v << ", r=" << r << endl;

    return 0;
}
