/** 
 * @file src/stream-eccezioni-2.cpp
 * Programma di esempio per la gestione delle eccezioni.
 */
 
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{    
    ifstream testo;

    try {
        
        testo.exceptions ( ios_base::failbit );
        testo.open("fileinesistente.txt");        
        testo.close();
        
    } catch(ios_base::failure e) {
     
        cerr << "Errore in esecuzione" << endl;      
   
    }    
   
    return 0;
}
