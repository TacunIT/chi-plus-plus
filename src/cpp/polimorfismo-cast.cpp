/** 
 * @file src/polimorfismo-cast.cpp
 * Gestione della conversione esplicita.
 */

#include <iostream>

using namespace std;

class Frazione
{
private:
    
    int _num ;
    int _den ;

public:
    
    /** Costruttore con parametri interi */
    Frazione(int n, int d = 1) 
    : _num(n), _den(d) {} 
    
    /** 
     * Costruttore con parametro a virgola mobile.
     * La definizione è piuttosto complessa, te la risparmio.  
     */
    Frazione(double d) ;

    /** Overload dell'operatore di cast a intero */
    operator int () { 
        return _num / _den ; 
    }

    /** Overload dell'operatore di cast a double */
    operator double() { 
        return (double) _num / (double) _den ; 
    }

    /** Overload degli operatori di somma e sottrazione */
    friend Frazione operator+ (Frazione f1, Frazione f2); 
    friend Frazione operator- (Frazione f1, Frazione f2); 

};
