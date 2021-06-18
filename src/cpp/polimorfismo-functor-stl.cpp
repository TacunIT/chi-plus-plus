/** 
 * @file src/polimorfismo-functor-stl.cpp
 * Esempio di function objects della STL.
 */

#include <iostream>
#include <functional>

using namespace std;

int main ()
{
    int a = 12;
    int b = 4;

    /** Dichiarazione di oggetti functor */
    plus<int>       p;
    minus<int>      m;
    multiplies<int> x;
    divides<int>    d;
    modulus<int>    o;

    /** Utilizzo degli oggetti come fossero delle funzioni */
    cout << "plus: "       << p(a,b) << endl;
    cout << "minus: "      << m(a,b) << endl;
    cout << "multiplies: " << x(a,b) << endl;
    cout << "divides: "    << d(a,b) << endl;
    cout << "modulus: "    << o(a,b) << endl;

    /** "esegue"" l'oggetto o con nuovi parametri */
    cout << "modulus: "    << o(a,5) << endl;

    return 0;
}
