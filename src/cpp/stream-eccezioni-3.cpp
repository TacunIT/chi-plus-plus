/** 
 * @file src/stream-eccezioni-3.cpp
 * Programma di esempio per la gestione delle eccezioni.
 */
 
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{    
    ifstream testo;

    try {
        
        /** Verifica che esista il nome del file da aprire */
        if(argc < 2)
            throw "Nome file mancante";
            
        testo.exceptions ( ios_base::failbit );
        testo.open(argv[1]);        
        testo.close();
        
    } catch(ios_base::failure e) {
     
        cerr << "Errore in esecuzione" << endl;      
   
    } catch(char const* msg) {
        
        cerr << msg << endl;
    }
   
    return 0;
}
