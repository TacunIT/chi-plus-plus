/**
 * @file data-types-limits.cpp
 * Shows the possible values for C++'s main data types.
 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
/**
 * Template function that shows the size and the
 * minimum and maximum values for a data type.
 */
template<typename T>
void limits()
{
    cout << sizeof(T) << " bytes,"
         << setw(4)   << "da:"
         << setw(21)  << numeric_limits<T>::min()
         << setw(4)   << "a:"
         << setw(21)  << numeric_limits<T>::max()
         << endl;
}
int main()
{
    /** Variation of the size and values of the int type */
    cout << setw(16) << "int: ";
    limits<int>();
    cout << setw(16) << "unsigned int: ";
    limits<unsigned int>();
    cout << setw(16) << "short int: ";
    limits<short int>();
    cout << setw(16) << "unsigned short: ";
    limits<unsigned short>();
    cout << setw(16) << "long int: ";
    limits<long int>();
    cout << setw(16) << "unsigned long: ";
    limits<unsigned long>();

    return 0;
}
