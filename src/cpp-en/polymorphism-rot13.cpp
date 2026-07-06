/**
 * @file src/polymorphism-rot13.cpp
 * Transforming a string with a function.
 */

#include <string>
#include <cctype>
#include <iostream>

using namespace std;

/**
*   Function that converts the characters of a string to rot13
*   ROT13 is a fairly trivial cipher algorithm,
*   because it shifts the value of each character by 13.
*   It isn't a truly secure algorithm, though, because to
*   decrypt the encrypted text all you need to do is encrypt
*   it again.
*/
unsigned char rot13(unsigned char c)
{
    unsigned char rot = c;
    if (isalpha(c)) {
        rot = ((tolower(c) - 'a') < 14) ? c + 13 : c - 13;
    }
    return rot;
}

int main ()
{
    string fb("Foobar");

    /** Processes the string with the transform function */
    transform(
               fb.begin()   // start of the container to modify
             , fb.end()     // end of the container to modify
             , fb.begin()   // output container
             , rot13        // function to apply
             );

    cout << fb << endl;

    /** Repeating the operation restores the original text. */
    transform(
               fb.begin()
             , fb.end()
             , fb.begin()
             , rot13
             );

    cout << fb << endl;

    return 0;
}
