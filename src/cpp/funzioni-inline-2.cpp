/** 
 * @file funzioni-inline-2.cpp
 * Esempio di funzione inline.
 */

#include <iostream>
#include <iomanip> 
#include <fstream> 

#define S_FILENAME  "src/out/esempio.txt"

using namespace std;

/** Funzione di output inline */
inline void log(const char* messaggio)
{
    /** Mostra il messaggio a video */
    cout << messaggio << endl;
}

int main(int argc, char** argv)
{        
    /** Dichiara il file di output */
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
