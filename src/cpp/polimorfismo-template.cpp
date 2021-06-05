/** 
 * @file src/polimorfismo-template.cpp
 * Esempio di funzione template.
 */

#include <iostream>
#include <functional>

using namespace std;

/**
*  Definzione di una macro istruzione per il 
*  precompilatore: nessun controllo di tipo.
*/
#define MAGGIORE(a,b) ((a > b) ? a : b) 

/**
*  Definzione di una funzione template
*  che torna il maggiore fra due parametri.
*/
template<class T>
T maggiore (T x, T y) {
    return (x > y) ? x : y;
}

int main ()
{    
    /** Utilizzo della macro */
    cout << MAGGIORE(9,12)     << endl;    
    cout << MAGGIORE(0.4, 1.2) << endl;    
    cout << MAGGIORE('a', 'z') << endl;    

    /** 
    *  La stessa funzione si può utilizzare 
    *  con tipi di dato diversi:
    */
    cout << maggiore(  9,  12) << endl;    
    cout << maggiore(0.4, 1.2) << endl;    
    cout << maggiore('a', 'z') << endl;    

    return 0;
}
