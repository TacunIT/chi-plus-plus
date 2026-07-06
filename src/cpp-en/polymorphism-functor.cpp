/**
 * @file src/polymorphism-functor.cpp
 * Creating a functor class.
 */

#include <string>
#include <cctype>
#include <iostream>
#include <functional>

using namespace std;

/** Declaration of the functor class */
class Cipher
{
private:

    int _key;

public:

    /**
    *   The class's constructor takes as a parameter
    *   the value of the encryption key
    */
    Cipher(int key) : _key(key) {  }

    /** Redefinition of the () operator */
    unsigned char operator () (unsigned char c) const {
        return c + _key;
    }
};

int main ()
{
    string fb("Foobar");

    /**
    *   Calls transform passing as a parameter
    *   an instance of the functor, initialized with
    *   the encryption key.
    */
    transform(
               fb.begin()
             , fb.end()
             , fb.begin()
             , Cipher(1)
             );

    cout << fb << endl;

    return 0;
}
