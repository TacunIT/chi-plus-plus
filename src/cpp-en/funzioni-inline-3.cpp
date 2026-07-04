/** 
 * @file funzioni-inline-3.cpp
 * Esempio di funzione inline.
 */

#include <iostream>
#include <iomanip> 
#include <fstream> 

#define LOG_DEBUG   1
#define LOG_AVVISO  2
#define LOG_ERRORE  3

#define S_DEBUG     "debug"
#define S_AVVISO    "avviso"
#define S_ERRORE    "errore"

#define ERR_NO_FILE_NAME  -1
#define ERR_NO_FILE_OPEN  -2

using namespace std;

/** Funzione di output inline */
inline void log(const char* messaggio, int livello)
{
    /** Definisce la spaziatura del primo campo */
    cerr << setw(7);  
    
    /** Scrive il livello del messaggio */
    switch(livello) {
        case LOG_DEBUG:  cerr << S_DEBUG ; break;
        case LOG_AVVISO: cerr << S_AVVISO; break;
        default:         cerr << S_ERRORE; break;
    }
    
    /** Scrive il testo del messaggio */
    cerr << ": " << messaggio << endl;
}

int main(int argc, char** argv)
{        
    /** Crea una variabile per gestire il file di output */
    ofstream doc;

    /** Puntatore per il nome del file di output */
    const char* filename = NULL;

    /** Se manca il nome del file di output, errore */
    if(argc < 2) {
        log("specificare il path del file", LOG_ERRORE);
        return ERR_NO_FILE_NAME;
    }
    
    /** Legge il nome del file di output */
    filename = argv[1];
    
    /** Prova ad aprire il file di output */    
    doc.open (argv[1]);
    
    /** Se c'è stato un errore, lo segnala ed esce */
    if(!doc.is_open()) {
        log("impossibile aprire il file", LOG_ERRORE);    
        return ERR_NO_FILE_OPEN;    
    }
    
    /** OK, il file è pronto */
    log("ho aperto il file", LOG_AVVISO);

    /** Scrive sul file di output */
    doc << "Testo del documento.\n";
    log("ho scritto sul file", LOG_DEBUG);

    /** Chiude il file di output */
    doc.close();
    log("ho chiuso il file", LOG_AVVISO);

    return 0;
}
