/** 
 * @file src/stream-eccezioni-1.cpp
 * Programma di esempio per la gestione delle eccezioni.
 */
 
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{    
    ifstream testo;

    /** 
    *   Fa sì che, se sia generata un'eccezione 
    *   in caso di errore nella gestione del file.
    */
    testo.exceptions ( ios_base::failbit );

    /** Questa istruzione genererà un'eccezione */
    testo.open("fileinesistente.txt");
    
    testo.close();
    
    return 0;
}
