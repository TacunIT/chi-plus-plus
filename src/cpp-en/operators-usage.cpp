/**
 * @file operators-usage.cpp
 * Example of operator usage.
 */

#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main(int argc, char** argv)
{
    int x = 12;
    int y = 4;

    cout << "Arithmetic operators" << endl;
    cout << "x + y = " << x + y << endl;
    cout << "x - y = " << x - y << endl;
    cout << "x * y = " << x * y << endl;
    cout << "x / y = " << x / y << endl;
    cout << "x % y = " << x % y << endl;
    cout << "x++   = " << x++ << endl;
    cout << "x--   = " << x-- << endl;
    cout << endl;

    cout << "Logical operators" << endl;
    cout << "x && y    = " << (x && y)  << endl;
    cout << "x || y    = " << (x || y)  << endl;
    cout << "!(x && y) = " << !(x && y) << endl;
    cout << endl;

    cout << "Relational operators"  << endl;
    cout << "x == y = " << (x == y)  << endl;
    cout << "x != y = " << (x != y)  << endl;
    cout << "x > y  = " << (x  > y)  << endl;
    cout << "x < y  = " << (x  < y)  << endl;
    cout << "x >= y = " << (x >= y)  << endl;
    cout << "x <= y = " << (x <= y)  << endl;
    cout << endl;

    cout << "Bitwise operators"  << endl;
    cout << "bit x  = " << bitset<8>(x) << endl;
    cout << "bit y  = " << bitset<8>(y) << endl;
    cout << "x & y  = " << bitset<8>(x & y)  << endl;
    cout << "x | y  = " << bitset<8>(x | y)  << endl;
    cout << "x ^ y  = " << bitset<8>(x ^ y)  << endl;
    cout << "x ~ y  = " << bitset<8>(~ y)    << endl;
    cout << "x >> y = " << bitset<8>(x >> y) << endl;
    cout << "x << y = " << bitset<8>(x << y) << endl;
    cout << endl;

    cout << "Assignment operators"  << endl;
    cout << "x += y = " << (x += y) << endl;
    cout << "x -= y = " << (x -= y) << endl;
    cout << "x *= y = " << (x *= y) << endl;
    cout << "x /= y = " << (x /= y) << endl;
    cout << "x %= y = " << (x %= y) << endl;
    cout << endl;

    return 0;
}
