/** 
 * @file memoria-statica.cpp
 * Gestione statica della memoria.
 */
 
#include <iostream>

/** Definisce la dimensione della stringa */
#define DIM_STRINGA 200

using namespace std;

int main(int argc, char** argv)
{    
    /** Riserva uno spazio di 200 caratteri */
    char stringa[DIM_STRINGA];

    /** 
    * Qui dovrebbe controllare che le stringhe ci siano 
    * e che, sommate, siano più corte di 200 caratteri.. 
    */
    
    /** Copia le stringhe nell'area di memoria */
    sprintf(stringa, "%s %s", argv[1], argv[2]);

    /** Stampa la stringa a video */
    cout << stringa << endl;
        
    return 0;
}
       
