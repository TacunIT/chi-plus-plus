/**
 * @file _man/src/functions-default-parameters.cpp
 * Example of a function with default parameters.
 */

#include <iostream>

using namespace std;

/** Function with default parameters  */
void printValue(int value = 0)
{
    /** Prints the parameter's value on screen */
    cout << "Value: " << value << endl;
}

int main(int argc, char** argv)
{
    /** Calls the function with an argument */
    printValue(123);

    /** Calls the function without arguments */
    printValue();

    return 0;
}
