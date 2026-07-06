/**
 * @file src/polymorphism-in-out.cpp
 * Operators as member or global functions.
 */

#include <iostream>

using namespace std;

struct A
{
    int _a;
    A(int a) : _a(a) {}
};

struct B
{
    int _b;
    B(int b) : _b(b) {};
    /** Overload as a member function */
    int operator + (const A& a) {
        return _b + a._a;
    }
};

/** Overload as a global function */
int operator + (const A& a, const B& b) { return a._a + b._b; }

int main ()
{
    struct A a(3);
    struct B b(5);

    cout << (a + (b + a)) << endl;

    return 0;
}
