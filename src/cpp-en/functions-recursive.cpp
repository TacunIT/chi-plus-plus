/**
 * @file /src/functions-recursive.cpp
 * Example of a recursive function.
 */

#include <iostream>
#include <iomanip>

using namespace std;

/** Declaration of the recursive function */
long factorial(int n);

/** Main function before the definition */
int main(int argc, char** argv)
{
    int n = 9;
    cout << n << "! = " << factorial(n) << endl;
    return 0;
}

/** Definition of the recursive function */
long factorial(int n)
{
    long fact = 1;
    if(n > 1) {
        fact = n * factorial(n-1);
    }
    return fact;
}
