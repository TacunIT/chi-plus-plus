/** 
 * @file src/stream-io.cpp
 * Programma di esempio per la gestione dell'I/O su stream.
 */
 
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{    
    ifstream in_file;
    ofstream out_file;
    
    
    /** Apre il file di input in lettura */
    in_file.open(argv[2]);            

    /** 
    *   Legge tutti i caratteri del file 
    *   e li scrive sullo schermo
    */
    while(in_file.good()) {
        if((c = in_file.get()) != EOF) {     
            letti++;
            cout << c;
        } 
    } 

    /** Chiude il file di input */
    in_file.close();
   
    return 0;
}
