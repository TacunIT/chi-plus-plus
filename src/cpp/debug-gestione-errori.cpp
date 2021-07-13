/** 
 * @file src/debug-gestione-errori.cpp
 * Modalità di gestione degli errori.
 */
 
#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

/** Codici e stringhe di errrore */
#define ERR_NONE          0
#define ERR_FILE_NONE   -10
#define ERR_FILE_OPEN   -20
#define ERR_FILE_READ   -30
#define S_ERR_FILE_NONE "Definire un file di input"
#define S_ERR_FILE_OPEN "Impossibile aprire il file di input"
#define S_ERR_FILE_READ "Impossibile leggere il file di input"

/**
*   Definisce una classe derivata da exception
*   per la gestione degli errori.
*/
class Eccezione: public exception
{
private:
    int         _codice;
    const char* _errore;
public:

    /** Costruttore */
    Eccezione(int codice, const char* errore) 
    : _codice(codice), _errore(errore) {        
    }
    
    /** Funzione virtuale pura: va ridefinita */
    virtual const char* what() const throw() {
        return _errore;
    }

    /** Funzioni di interfaccia */
    int getCodice() { return _codice; }
    const char* getErrore() { return _errore; }

    /** Ridefinizione dell'operatore di output */
    friend ostream& operator<< (ostream& os, Eccezione e){
        os << e._codice << ": " << e._errore << endl;
        return os;
    }
};

/** Funzione di gestione degli errori */
void errore(int codice, bool exit = true)
{
    const char* errore = NULL;

    /** 
    *   Identifica la stringa di errore corrispondente 
    *   al codice di errore ricevuto.
    */
    switch(codice) {
        case ERR_FILE_NONE: errore = S_ERR_FILE_NONE; break;
        case ERR_FILE_OPEN: errore = S_ERR_FILE_OPEN; break;
        case ERR_FILE_READ: errore = S_ERR_FILE_READ; break;
    }

    /** Se ne trova una, lancia un'eccezione */
    if(errore != NULL   ){
        Eccezione e(codice, errore);
        throw e;
    }
}

/** Verifica la presenza dei parametri di avvio */
int verifica_parametri(int argc, char** argv)
{
    return (argc < 2) ? ERR_FILE_NONE : ERR_NONE;
} 

/** Apre il file in lettura */
int apri_file(ifstream& testo, const char* path)
{
    cout << "Apro il file: " << path << endl;
    testo.open(path);
    return ERR_NONE;
} 

/** Legge il file di input e lo scrive a video */
int elabora_file(ifstream& testo)
{
    int  letti = 0;
    char c = 0;
    while ((c = testo.get()) != EOF) {            
        letti++;
        cout << c;            
    } 
    return letti;
} 

/** Chiude il file di input */
void chiudi_file(ifstream& testo)
{
    testo.close();
} 
 
int main(int argc, char** argv)
{    
    ifstream testo;
    
    try {
        
        int esito = ERR_NONE;
        
        /** 
        *   Verifica che ci sia il nome del file di input 
        *   e gestisce eventuali errori.
        */
        esito = verifica_parametri(argc, argv);
        errore(esito);
        
        /** 
        *   Imposta la exception mask dello stream per fare
        *   sì che un errore di I/O generi un'eccezione,
        *   poi apre il file in lettura.
        *   Usa un blocco try/catch per intercettare una
        *   eventuale eccezione e gestirla in maniera
        *   omogenea al resto del codice.
        *   Non può mettere solo una catch in fondo perché
        *   l'eccezione non dà informazioni sulla causa 
        *   dell'errore che l'ha generata.
        */
        try {
            testo.exceptions ( std::ifstream::badbit 
                             | std::ifstream::failbit );
            esito = apri_file(testo, argv[1]);            
        } catch(ifstream::failure e) {
            errore(ERR_FILE_OPEN);            
        }
        
        /** 
        *   Elabora il testo e gestisce eventuali errori.
        *   Dato che la funzione torna il numero di 
        *   caratteri letti, deve chiamare errore solo
        *   se non ce ne sono.
        */
        testo.exceptions ( std::ifstream::goodbit);
        if(elabora_file(testo) == 0) {
            errore(ERR_FILE_READ);            
        }
        
        
        /** Chiude il file di input */
        chiudi_file(testo);
    
    } catch (Eccezione e) {
        cerr << e;
        exit(e.getCodice());
    }
    
    return 0;
}
