/** 
 * @file src/polimorfismo-functor.cpp
 * Esempio di function objects della STL.
 */

#include <iostream>
#include <functional>

using namespace std;

/** Classe che incapsula la funzione di output */
class coutput {
public:
    /** 
     * Ridefinizione dell'operatore () 
     * come funzione template 
     */
    template<class T>
    ostream& operator () (T n) {
        cout << n << endl;
        return cout;
    }
};

int main ()
{
    int a = 12;
    int b = 4;

    /** Istanza della classe coutput */
    coutput c; 

    /** Functor della STL */
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

    /** Richiama l'oggetto con nuovi parametri */
    cout << "modulus: "    << o(a,5) << endl;

    /** Output con la classe coutput */
    c(23);
    c("PippoPluto");
    
    return 0;
}
