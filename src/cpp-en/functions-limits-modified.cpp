/**
 * @file functions-limits-modified.cpp
 * Example on C++ limits with output in a single function.
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;

/**
 * Displays the name, the size, and the minimum and
 * maximum values for the current data type.
 */
template<typename T>
void dimension()
{
    cout << setw(14)
         << abi::__cxa_demangle(typeid(T).name(), NULL, NULL, NULL)
         << ": "
         << sizeof(T) << " bytes,"
         << setw(6)   << "from:"
         << setw(21)  << numeric_limits<T>::min()
         << setw(4)   << "to:"
         << setw(21)  << numeric_limits<T>::max()
         << endl;
}

/**
 * The new code of the main function: more compact
 * and easier to read or modify.
 */
int main(int argc, char** argv)
{
    dimension<int>();
    dimension<short int>();
    dimension<unsigned short>();
    dimension<long int>();
    dimension<unsigned long>();
    return 0;
}
