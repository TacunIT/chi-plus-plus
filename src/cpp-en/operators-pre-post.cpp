/**
 * @file _man/src/operators-pre-post.cpp
 * Use of the increment and decrement operators.
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    /** Defines the two variables */
    int pre  = 5, post = 7;

    /** Increment operator, before and after the variable */
    cout << "pre-increment: "  << ++pre  << endl;
    cout << "post-increment:" << post++ << endl;

    /** Decrement operator, before and after the variable */
    cout << "pre-decrement: "  << --pre  << endl;
    cout << "post-decrement:" << post-- << endl;

    return 0;
}
