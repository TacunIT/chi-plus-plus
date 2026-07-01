/** 
 * @file src/polimorfismo-functor.cpp
 * Creazione di una classe functor.
 */

#include <string>
#include <cctype>
#include <iostream>
#include <functional>

using namespace std;

/** Dichiarazione della classe functor */
class Cifra
{
private:

    int _chiave;

public:
    
    /** 
    *   Il costruttore della classe ha come parametro
    *   il valore della chiave di cifratura
    */
    Cifra(int chiave) : _chiave(chiave) {  }
  
    /** Ridefinizione dell'operatore () */
    unsigned char operator () (unsigned char c) const {
        return c + _chiave;
    }
};

int main ()
{
    string pp("PippoPluto"); 

    /** 
    *   Richiama transform passando come parametro
    *   un'istanza del functor, inizializzata con 
    *   la chiave di cifratura.
    */
    transform(
               pp.begin()   
             , pp.end()     
             , pp.begin()   
             , Cifra(1)        
             );

    cout << pp << endl; 
    
    return 0;
}
