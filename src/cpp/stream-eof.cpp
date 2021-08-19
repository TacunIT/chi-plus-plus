/** 
 * @file src/stream-eof.cpp
 * Gestione dell'I/O su file con gli stream.
 */
 
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{    
    ifstream testo;
    
    /** apre il file in lettura */
    testo.open(argv[1]);
    
    /** Verifica che il file sia aperto */
    if(testo.is_open()) {
        
        /** Utilizza eof per gestire il ciclo */
        while(!testo.eof()) {

            int n;

            /** Legge un numero dal file */
            testo >> n;

            /** Lo scrive a video */
            cout << n << endl;
        }
        
    }
        
    /** Chiude il file di input */
    testo.close();
    
    return 0;
}
