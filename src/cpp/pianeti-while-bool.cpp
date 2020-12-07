/** 
 * @file pianeti-while-bool.cpp
 * Gestione dei Pianeti con istruzione while.
 */
 
#include <iostream>
#include "pianeti.h"

using namespace std;

int main(int argc, char** argv)
{    
    int  p  = POS_MERCURIO;

    /** Assegna un valore alla variabile di controllo */
    bool ok = true;

    /** Ripete l'azione finché la variabile è uguale a true */
    while (ok) {

        /** Mostra il valore di p e lo incrementa */
        cout << p++ << ": "; 

        /** 
         * Mostra il nome sel pianeta e salva l'esito della 
         * funzione nella variabile ok 
         */
        ok = mostraPianeta(p);

        /** Aggiunge il solito a capo */
        cout << endl;
    }
        
    return 0;
}
