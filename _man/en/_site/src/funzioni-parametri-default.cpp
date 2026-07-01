/** 
 * @file _man/src/funzioni-parametri-default.cpp
 * Esempio di funzione con parametri di default.
 */

#include <iostream>

using namespace std;

/** Funzione con parametri di default  */
void stampaValore(int valore = 0)
{
    /** Stampa a video il valore del parametro */
    cout << "Valore: " << valore << endl;
}

int main(int argc, char** argv)
{        
    /** Richiama la funzione con un argomento */
    stampaValore(123);

    /** Richiama la funzione senza argomenti */
    stampaValore();

    return 0;
}
