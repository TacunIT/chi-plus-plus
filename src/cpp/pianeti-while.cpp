/** 
 * @file pianeti-while.cpp
 * Gestione dei Pianeti con istruione while.
 */
 
#include <iostream>
#include "pianeti.h"

using namespace std;

int main(int argc, char** argv)
{    
    int  p  = POS_MERCURIO;
    bool ok = true;

    /** Elenca tutti i Pianeti del Sistema Solare */
    while (ok) {
        cout << p++ << ": "; 
        ok = mostraPianeta(p);
        cout << endl;
    }
        
    return 0;
}
