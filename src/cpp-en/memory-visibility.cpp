/**
 * @file memory-visibility.cpp
 * Visibility of variables.
 */

#include <iostream>

using namespace std;

/**
 * Variables defined outside of functions
 * are called "global variables" and are visible
 * throughout the code.
 */
const char* str = "Global string";

void func()
{
    /**
     * Variables defined inside a
     * function are only visible inside
     * the function itself.
     */
    const char* str = "Outer string";

    /** Generic code block */
    {
        /**
         * Variables defined inside a
         * code block are only visible
         * inside the code block.
         */
        const char* str = "Inner string";

        /** Shows the inner variable */
        cout << "block: " << str << endl;
    }

    /**
     * Here the outer variable is visible.
     */
    cout << "func:   " << str << endl;

    /**
     * The :: operator lets you access the
     * global variable.
     */
    cout << "func:   " << ::str << endl;

}

int main(int argc, char** argv)
{
    /** Calls the outer function */
    func();

    /**
     * The main function doesn't define a
     * "str" variable, so it shows the global variable.
     */
    cout << "main:   " << str << endl;

    return 0;
}
