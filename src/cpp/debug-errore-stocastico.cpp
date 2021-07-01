/** 
 * @file debug-errore-stocastico.cpp
 * Gestione dei Pianeti con errore evidente.
 */
 
#include <iostream>
#include <fstream>

using namespace std;

#define ERR_FILE_NONE       -10
#define ERR_FILE_OPEN       -20
#define S_ERR_FILE_NONE     "Definire un file di input"
#define S_ERR_FILE_OPEN     "Impossibile aprire il file di input"
#define N_CHAR_MIN          300
#define N_BANNER_MAX        3
#define PUNTO               '.'

/**
 * Aggiunge un banner dopo ogni punto, ogni N_CHAR_MIN caratteri.
 */
int banner_testo(ifstream& testo)
{
    int  n_banner = 1;
    int  letti = 0;
    char c = 0;
 
    /** 
    *   Verifica che il file sia valido. 
    *   Lo fa anche la funzione chiamante, 
    *   ma non è detto che sarà sempre così..
    */
    while(testo.good()) {
        
        /** Legge il file, carattere per carattere */
        if((c = testo.get()) != EOF) {            

            /** Incrementa il numero di caratteri letti */
            letti++;

            /** Scrive il carattere letto */
            cout << c;            

            /** 
            *   Se il carattere corrente è un punto
            *   e ha letto almeno N_CHAR_MIN caratteri
            *   e ha ancora banner da aggiungere, 
            *   inserisce il codice del banner nel testo. 
            */
            if(c == PUNTO 
            && letti >= N_CHAR_MIN 
            && n_banner <= N_BANNER_MAX) {                
                cout << endl 
                     << "<div id=\"banner-" << n_banner << "\">"
                     << "</div>" 
                     << endl;
                n_banner++;
                letti = 0;
            }
        }       
    } 
    
    cout << endl;
    
    return n_banner;
} 
 
int main(int argc, char** argv)
{    
    ifstream testo;
    
    /** Verifica che ci sia il nome del file di input */
    if(argc < 2) {
        cerr << S_ERR_FILE_NONE << endl;
        exit(ERR_FILE_NONE);
    }
    
    /** Apre il file in lettura */
    testo.open(argv[1]);
    if(!testo.good()) {
        cerr << S_ERR_FILE_OPEN << endl;
        exit(ERR_FILE_OPEN);
    }

    /** Elabora il testo */
    banner_testo(testo);
    
    /** Chiude il file */
    testo.close();
    
    return 0;
}
