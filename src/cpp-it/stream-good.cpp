/** 
 * @file src/stream-good.cpp
 * Gestione dell'I/O su file con gli stream.
 */
 
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{    
    ifstream testo;
    int      n;
    
    /** apre il file in lettura */
    testo.open(argv[1]);
    
    /** 
    *   Il ciclo si ripete fino a che non 
    *   si verifica un errore
    */
    while(testo.good()) {

        /** Legge un numero dal file */
        testo >> n;

        /** Si interrompe se il file è finito */
        if(testo.eof()) break;
        
        /** Altrimenti, scrive il numero */
        cout << n << endl;
    }
                
    /** Chiude il file di input */
    testo.close();
    
    return 0;
}
