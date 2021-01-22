/** 
 * @file funzioni-inline.cpp
 * Esempio di funzione inline.
 */

#include <iostream>
#include <iomanip> 
#include <ifstream> 

#define LOG_DEBUG   1
#define LOG_AVVISO  2
#define LOG_ERRORE  3

#define S_DEBUG     "debug"
#define S_AVVISO    "avviso"
#define S_ERRORE    "errore"

#define S_FILENAME  "src/out/esempio.txt"

using namespace std;

/** Funzione di output inline */
inline void log(int livello, const char* messaggio)
{
    cerr << setw(7);  
    switch(livello) {
        case LOG_DEBUG:  cerr << S_DEBUG ; break;
        case LOG_AVVISO: cerr << S_AVVISO; break;
        default:         cerr << S_ERRORE; break;
    }
    cerr << ": " << messaggio << endl;
}

int main(int argc, char** argv)
{        
    /** Dichiara il file di output */
    ofstream doc;

    /** Apre il file di output */
    doc.open (S_FILENAME);
    log(LOG_DEBUG, "ho aperto il file", S_FILENAME);

    /** Scrive sul file di output */
    doc << "Testo del documento.\n";
    log(S_DEBUG, "ho scritto sul file", S_FILENAME);

    /** Chiude il file di output */
    doc.close();
    log(S_AVVISO, "ho chiuso il file", S_FILENAME);

    return 0;
}
