/** 
 * @file src/polimorfismo-macro-template.cpp
 * Funzioni template e macro precompilatore.
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
    int    a = 10;
    short  b = 0;   
    double d = 3.123456789;
    
    /** Utilizzo della macro */
    cout << MAGGIORE(9,12)     << endl;    
    cout << MAGGIORE(0.4, 0.7) << endl;    
    cout << MAGGIORE('a', 'z') << endl;    

    /** 
    *  La stessa funzione si può utilizzare 
    *  con tipi di dato diversi:
    */
    cout << maggiore<int>   (  9,  12) << endl;    
    cout << maggiore<double>(0.4, 1.2) << endl;    
    cout << maggiore<char>  ('a', 'z') << endl;    
   
    /** Errore: confronta un carattere con un double */
    cout << MAGGIORE('a', d) << endl;    

    /**
    *   Errore: il compilatore non sa quale
    *   dei due tipi di dato utilizzare.
    */
    cout << maggiore(a, b) << endl;    
    
    return 0;
}
