/** 
 * @file pianeti-main.cpp
 * Funzione princopale per il programma di gestione dei Pianeti.
 */
 
#include <iostream>
#include "pianeti.h"

using namespace std;

int main(int argc, char** argv)
{    
    int p = POS_MERCURIO;

    /** Elenca tutti i Pianeti del Sistema Solare */
    for ( ; ; ) {
        cout << p << ": "; 
        /** Se incontra un errore, si ferma */
        if(!mostraPianeta( p++ )) break; 
        cout << endl;
    }
        
    cout << endl;

    return 0;
}
