/** 
 * @file src/polimorfismo-in-out.cpp
 * Operatori come funzioni membro o globali.
 */

#include <iostream>
#include <string>

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
    /** Overload come funzione membro */
    int operator + (const A& a) {
        return _b + a._a;
    };
};

/** Overload come funzione globale */
int operator + (const A& a, const B& b) { return a._a + b._b; }

int main ()
{
    struct A a(3);
    struct B b(5);
                
    cout << (a + (b + a)) << endl;

    return 0;
}
