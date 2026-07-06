/**
 * @file functions-arguments.cpp
 * Example of how function arguments are handled.
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/**
*   Call by value: whatever happens here to the
*   variables a and b has no effect on the x and y
*   variables of the calling function.
*/
void byValue(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

/**
*   Call by reference: whatever happens here to the
*   variables a and b is as if it were done to the
*   x and y variables of the calling function.
*/
void byReference(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

/**
*   Call by pointer: here too, whatever happens to
*   the variables a and b also happens to the x and y
*   variables of the calling function, but the code
*   is less clear.
*/
void byPointer(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int main(int argc, char** argv)
{
    int  x = 11; int  y = 22;
    cout << setw(20) << "Initial value: x=" << x << ", y=" << y << endl;

    int* p = &x;
    int& r = x;

    cout << "p:" << p << ",r=" << r << endl;

    /**
    *   Passing by value: the argument of the function
    *   call is the value of the variables x and y:
    */
    byValue(x,y);
    cout << setw(20) << "byValue: x=" << x << ", y=" << y << endl;

    /**
    *   Passing by reference: the arguments of the function
    *   call are the variables x and y, but the function
    *   will use aliases of them, not their value:
    */
    byReference(x,y);
    cout << setw(20) << "byReference: x=" << x << ", y=" << y << endl;

    /**
    *   Passing by pointer: the argument of the call
    *   is explicitly the address of the variables x and y:
    */
    byPointer(&x,&y);
    cout << setw(20) << "byPointer: x=" << x << ", y=" << y << endl;

    return 0;
}
