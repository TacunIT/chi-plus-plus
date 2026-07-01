/** 
 * @file funzioni-inline-2.cpp
 * Esempio di codice con funzione di output unica.
 */

#include <iostream>
#include <iomanip> 
#include <fstream> 

#define S_FILENAME  "src/out/esempio.txt"

using namespace std;

/** Funzione di output unica */
void log(const char* messaggio)
{
    /** Mostra il messaggio a video */
    cout << messaggio << endl;
}

int main(int argc, char** argv)
{        
    /** Crea una variabile per gestire il file di output */
    ofstream doc;

    /** Apre il file di output */
    doc.open (S_FILENAME);
    log("ho aperto il file");

    /** Scrive sul file di output */
    doc << "Testo del documento.\n";
    log("ho scritto sul file");

    /** Chiude il file di output */
    doc.close();
    log("ho scritto il file");

    return 0;
}
