/**
 * @file src/preprocessor-macro.cpp
 * Example of a precompiler macro instruction.
 */

#include <iostream>

using namespace std;

/**
*  Definition of a macro instruction that
*  returns the greater of two parameters.
*/
#define GREATER(a,b) ((a > b) ? a : b)

int main ()
{
    /**
     *  The code of these instructions is replaced
     *  with the one associated with the macro:
     *
     *      cout << ((109 > 122) ? 109 : 122) << endl;
     *      cout << ((0.4 > 0.7) ? 0.4 : 0.7) << endl;
     *      cout << (('a' > 'z') ? 'a' : 'z') << endl;
    */
    cout << GREATER(209, 122) << endl;
    cout << GREATER(0.4, 0.7) << endl;
    cout << GREATER('y', 'z') << endl;

    return 0;
}
