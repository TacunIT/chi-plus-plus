/** 
 * @file operatori-utilizzo.cpp
 * Esempio di utilizzo degli operatori.
 */

#include <iostream>
#include <iomanip> 
#include <bitset> 

using namespace std;

int main(int argc, char** argv)
{        
    int x = 12;
    int y = 4;

    cout << "Operatori aritmetici" << endl;
    cout << "x + y = " << x + y << endl;
    cout << "x - y = " << x - y << endl;
    cout << "x * y = " << x * y << endl;
    cout << "x / y = " << x / y << endl;
    cout << "x % y = " << x % y << endl;
    cout << "x++   = " << x++ << endl;
    cout << "x--   = " << x-- << endl;
    cout << endl;
    
    cout << "Operatori logici" << endl;
    cout << "x && y    = " << (x && y)  << endl;
    cout << "x || y    = " << (x || y)  << endl;
    cout << "!(x && y) = " << !(x && y) << endl;
    cout << endl;

    cout << "Operatori di relazione"  << endl;
    cout << "x == y = " << (x == y)  << endl;
    cout << "x != y = " << (x != y)  << endl;
    cout << "x > y  = " << (x  > y)  << endl;
    cout << "x < y  = " << (x  < y)  << endl;
    cout << "x >= y = " << (x >= y)  << endl;
    cout << "x <= y = " << (x <= y)  << endl;
    cout << endl;

    cout << "Operatori bitwise"  << endl;
    cout << "bit x  = " << bitset<8>(x) << endl;
    cout << "bit y  = " << bitset<8>(y) << endl;
    cout << "x & y  = " << bitset<8>(x & y)  << endl;
    cout << "x | y  = " << bitset<8>(x | y)  << endl;
    cout << "x ^ y  = " << bitset<8>(x ^ y)  << endl;
    cout << "x ~ y  = " << bitset<8>(~ y)    << endl;
    cout << "x >> y = " << bitset<8>(x >> y) << endl;
    cout << "x << y = " << bitset<8>(x << y) << endl;
    cout << endl;

    cout << "Operatori di assegnazione"  << endl;
    cout << "x += y = " << (x += y) << endl;
    cout << "x -= y = " << (x -= y) << endl;
    cout << "x *= y = " << (x *= y) << endl;
    cout << "x /= y = " << (x /= y) << endl;
    cout << "x %= y = " << (x %= y) << endl;
    cout << endl;

    return 0;
}
