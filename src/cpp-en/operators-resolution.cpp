/**
 * @file _man/src/operators-resolution.cpp
 * Use of the scope resolution operator.
 */

#include <iostream>

using namespace std;

const char * String = "Global string" ;

int main(int argc, char** argv)
{
    const char * String = "Local string" ;

    /** Prints the local string */
    cout << String   << endl ;

    /** Uses the operator to refer to the global variable */
    cout << ::String << endl ;

    return 0;
}
