/**
 * @file src/stream-input-2.cpp
 * Example program for handling stream input.
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char   buffer[256];
    string str;

    /**
    *   Reads a string from the keyboard using
    *   the istream class's member function.
    */
    cout << "Enter a string: ";
    cin.getline(buffer, 256);
    cout << buffer << endl;


    /**
    *   Reads a string from the keyboard using
    *   the global getline function.
    */
    cout << "Enter a string: ";
    getline(cin, str);
    cout << str << endl;

    return 0;
}
