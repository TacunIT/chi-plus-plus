/** 
 * @file pianeti-while-string.cpp
 * Gestione dei Pianeti con valori stringa.
 */
 
#include <iostream>
#include "pianeti.h"

using namespace std;

int main(int argc, char** argv)
{    
    int    p  = POS_MERCURIO;
    string nome;

    /** 
     * Scinde l'elaborazione del dato dalla sua
     * eventuale visualizzazione
     */
    while (!(nome = nomePianeta(p)).empty()) {
        cout << p++ << ": " << nome << endl;
    }
        
    return 0;
}
