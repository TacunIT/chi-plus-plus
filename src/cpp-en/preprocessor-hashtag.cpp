/**
 * @file src/preprocessor-hashtag.cpp
 * Examples of precompiler macro instructions.
 */

#include <iostream>

using namespace std;

/** Defines the macro instruction */
#define FUNCTION(name, parameter) int fn_##name() { return parameter; }

/**
*   During precompilation, this macro
*   will be replaced by the instruction:
*
*     int fn_macro(12) { return 12; }
*/
FUNCTION(macro, 12)

/**
*   Defines a macro that prints text to the screen:
*/
#define OUTPUT(text) cout << text << endl;

/**
*   Defines a macro that joins the string "Foo"
*   to the parameter it receives as input:
*/
#define FOO "Foo"
#define APPEND(name) FOO # name

int main()
{
    /**
    *   The fn_macro function doesn't exist right now, but it will
    *   exist once the code's precompilation is done:
    */
    cout << fn_macro() << endl;

    /** Prints a string to the screen using the other two macros */
    OUTPUT(APPEND(Bar));
}
