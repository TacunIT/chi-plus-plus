/** 
 * @file src/preprocessore-macro.cpp
 * Esempio di macro-istruzione del precompilatore.
 */

#include <iostream>

using namespace std;

/**
*  Definzione di una macro istruzione che
*  torna il maggiore fra due parametri.
*/
#define MAGGIORE(a,b) ((a > b) ? a : b) 

int main ()
{     
    /** 
     *  Il codice di queste istruzioni è sostituito
     *  con quello associato alla macro:
     *      
     *      cout << ((109 > 122) ? 109 : 122) << endl;    
     *      cout << ((0.4 > 0.7) ? 0.4 : 0.7) << endl;    
     *      cout << (('a' > 'z') ? 'a' : 'z') << endl;    
    */
    cout << MAGGIORE(209, 122) << endl;    
    cout << MAGGIORE(0.4, 0.7) << endl;    
    cout << MAGGIORE('y', 'z') << endl;    
    
    return 0;
}
