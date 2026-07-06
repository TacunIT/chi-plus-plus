/**
 * @file operators-others.cpp
 * Other C++ operators.
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int     a = 9;
    int     b = 4;

    /** Converts an integer value to char */
    char    c = char(a * b);

    /** Assigns to t the higher of the two values a and b */
    int     t = (a > b) ? a : b;

    /** Saves the memory address of a into the pointer p */
    int*    p = &a;

    /** Calculates the size of an integer */
    size_t sa = sizeof(a);

    /** Calculates the size of a pointer to an integer */
    size_t sp = sizeof(p);

    /** Shows the address of the variable a */
    cout << "&a: " << p  << endl;

    /** Shows the size of the variables a and p */
    cout << "sa: " << sa << endl;
    cout << "sp: " << sp << endl;

    /** Shows the result of the ternary operation */
    cout << "t : " << t  << endl;

    /** ASCII code 36 corresponds to the letter $ */
    cout << "c : " << c  << endl;

    cout << endl;

    return 0;
}
