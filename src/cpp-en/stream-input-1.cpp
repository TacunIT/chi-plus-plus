/**
 * @file src/stream-input-1.cpp
 * Example program for handling stream input.
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string str;

    /** Writes a message to the screen */
    cout << "Enter a string: ";

    /** Reads a string from the keyboard */
    cin >> str;

    /** Writes it to the screen */
    cout << str << endl;

    return 0;
}
