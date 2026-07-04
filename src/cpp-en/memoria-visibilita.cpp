/** 
 * @file memoria-visibilita.cpp
 * Visibilità delle variabili.
 */
 
#include <iostream>

using namespace std;

/** 
 * Le variabili definite all'esterno delle funzioni
 * si chiamano "variabili globali" e sono visibili
 * in tutto il codice. 
 */
const char* stringa = "Stringa globale";

void funz() 
{    
    /** 
     * Le variabili definite all'interno di una 
     * funzione sono visibili solo all'interno
     * della funzione stessa. 
     */
    const char* stringa = "Stringa esterna";
    
    /** Blocco di codice generico */
    {
        /** 
         * Le variabili definite all'interno di un 
         * blocco di codice sono visibili solo 
         * all'interno del blocco di codice. 
         */
        const char* stringa = "Stringa interna";
        
        /** Mostra la variabile interna */
        cout << "blocco: " << stringa << endl;
    }

    /** 
     * Qui è visibile la variabile esterna. 
     */
    cout << "funz:   " << stringa << endl;

    /** 
     * L'operatore :: permette di accedere alla 
     * variabile globale. 
     */
    cout << "funz:   " << ::stringa << endl;
    
}

int main(int argc, char** argv)
{    
    /** Richiama la funzione esterna */
    funz();

    /** 
     * La funzione main non definisce una variabile
     * "stringa", quindi mostra la variabile globale. 
     */
    cout << "main:   " << stringa << endl;
    
    return 0;
}
