/** 
 * @file src/stream-eccezioni-4.cpp
 * Programma di esempio per la gestione delle eccezioni.
 */
 
#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

/** Codici e stringhe di errore */
#define ERR_NONE          0
#define ERR_FILE_NONE   -10
#define ERR_FILE_OPEN   -20
#define S_ERR_FILE_NONE "Definire un file di input"
#define S_ERR_FILE_OPEN "Impossibile aprire il file di input"

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

int main(int argc, char** argv)
{    
    ifstream testo;
    testo.exceptions ( ios_base::badbit );

    try {

        char c     = 0;
        int  letti = 0;
                    
        /** 
        *   Verifica che ci siano sia il nome del file di input 
        *   che il numero di caratteri da leggere.
        */
        if (argc < 3) 
            throw Eccezione(ERR_FILE_NONE, S_ERR_FILE_NONE);
            
        /** Definisce il numero di caratteri da leggere */
        int da_leggere = atoi(argv[1]);
        
        /** 
        *   Imposta la exception mask dello stream per fare
        *   sì che un errore di I/O generi un'eccezione,
        *   poi apre il file in lettura.
        *   Usa un blocco try/catch per intercettare una
        *   eventuale eccezione e gestirla in maniera
        *   omogenea al resto del codice.
        */
        try {
            testo.exceptions ( ios_base::badbit 
                             | ios_base::failbit );
            testo.open(argv[2]);            
        } catch(ifstream::failure e) {
            throw Eccezione(ERR_FILE_OPEN, S_ERR_FILE_OPEN);      
        }

        /**
        *   Re-imposta la exception mask per evitare
        *   eccezioni a fine file.
        */
        testo.exceptions ( ios_base::goodbit);

        /** 
        *   Legge il testo e lo stampa a video 
        *   Se è stato definito un numero massimo di 
        *   caratteri, si ferma lì.
        */
        while(testo.good()) {
            if((c = testo.get()) != EOF) {     
                letti++;
                cout << c;
            } 
            if((da_leggere != 0) && (letti >= da_leggere)) {
                cout << endl;
                break;
            }
        } 
                
        /** Chiude il file di input */
        testo.close();
            
    } catch (Eccezione e) {

        /** Stampa a video l'eccezione */
        cerr << e;

        /** Esce con un codice di errore */
        exit(e.getCodice());
    }
    
    return 0;
}
