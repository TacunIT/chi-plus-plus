/** 
 * @file funzioni-variabili.cpp
 * Esempio di funzione con parametri variabili.
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

/** Funzione di output con parametri variabili */
void log(int livello, int n_parametri, ...)
{

    /** Definisce la spaziatura del primo campo */
    cerr << setw(8);  
    
    /** Scrive il livello del messaggio */
    switch(livello) {
        case LOG_DEBUG:  cerr << S_DEBUG ; break;
        case LOG_AVVISO: cerr << S_AVVISO; break;
        default:         cerr << S_ERRORE; break;
    }

    /** Scrive il carattere di separazione */
    cerr << " | ";

    /** Dichiara la variabile per gestire la lista dei parametri */    
    va_list lista_parametri;
    
    /** Inizializza la lista dei parametri */
    va_start(lista_parametri, n_parametri);

    /** Legge tutti i parametri nella lista e li scrive a video */
    for(int p = 1; p <= n_parametri; p++) {        
        cerr << va_arg(lista_parametri, char*) ;        
    }    

    /** Chiude la lista dei parametri */        
    va_end(lista_parametri);
    
    /** Scrive il testo del messaggio */
    cerr << endl;

}

int main(int argc, char** argv)
{        
    /** Crea una variabile per gestire il file di output */
    ofstream doc;

    /** Puntatore per il nome del file di output */
    const char* filename = NULL;

    /** Se manca il nome del file di output, errore */
    if(argc < 2) {
        log(LOG_ERRORE, 1, "specificare il path del file");
        return ERR_NO_FILE_NAME;
    }
    
    /** Legge il nome del file di output */
    filename = argv[1];
    
    /** Prova ad aprire il file di output */    
    doc.open (argv[1]);
    
    /** Se c'è stato un errore, lo segnala ed esce */
    if(!doc.is_open()) {
        log(LOG_ERRORE, 2, "impossibile aprire il file:", filename);    
        return ERR_NO_FILE_OPEN;    
    }
    
    /** OK, il file è pronto */
    log(LOG_AVVISO, 2, "ho aperto il file: ", filename);

    /** Scrive sul file di output */
    doc << "Testo del documento.\n";
    log(LOG_DEBUG, 2, "ho scritto sul file: ", filename);

    /** Chiude il file di output */
    doc.close();
    log(LOG_AVVISO, 2,  "ho chiuso il file: ", filename);

    return 0;
}
