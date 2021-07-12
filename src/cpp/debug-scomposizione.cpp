/** 
 * @file debug-errore-stocastico.cpp
 * Gestione dei Pianeti con errore evidente.
 */
 
#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

#define ERR_NONE              0
#define ERR_FILE_NONE       -10
#define ERR_FILE_OPEN       -20
#define ERR_FILE_READ       -30
#define S_ERR_FILE_NONE     "Definire un file di input"
#define S_ERR_FILE_OPEN     "Impossibile aprire il file di input"
#define S_ERR_FILE_READ     "Impossibile leggere il file di input"

class Eccezione: public exception
{
private:
    int         _codice;
    const char* _errore;
public:

    Eccezione(int codice, const char* errore) 
    : _codice(codice), _errore(errore) {        
    }
    
    virtual const char* what() const throw() {
        return _errore;
    }

    int getCodice() { return _codice; }
    
    friend ostream& operator<< (ostream& os, Eccezione e){
        os << e._codice << ": " << e._errore << endl;
        return os;
    }
};

void errore(int codice, bool exit = true)
{
    const char* errore = NULL;
    
    switch(codice) {
        case ERR_FILE_NONE: errore = S_ERR_FILE_NONE; break;
        case ERR_FILE_OPEN: errore = S_ERR_FILE_OPEN; break;                
    }

    if(errore != NULL   ){
        Eccezione e(codice, errore);
        throw e;
    }
}

int verifica_parametri(int argc, char** argv)
{
    return (argc < 2) ? ERR_FILE_NONE : ERR_NONE;
} 

int apri_file(ifstream& testo, const char* path)
{
    testo.open(path);
    return (testo.good()) ? ERR_NONE : ERR_FILE_OPEN;
} 

int elabora_file(ifstream& testo)
{
    int  letti = 0;
    char c = 0;
    while(testo.good()) {
        if((c = testo.get()) != EOF) {            
            letti++;
            cout << c;            
        }       
    } 
    return letti;
} 

void chiudi_file(ifstream& testo)
{
    testo.close();
} 
 
int main(int argc, char** argv)
{    
    ifstream testo;
    //testo.exceptions ( std::ifstream::failbit );
    
    try {
        
        int esito = ERR_NONE;
        
        /** Verifica che ci sia il nome del file di input */
        esito = verifica_parametri(argc, argv);
        errore(esito);
        
        /** Apre il file in lettura */
        esito = apri_file(testo, argv[2]);
        errore(esito);
        
        /** Elabora il testo */
        if(elabora_file(testo) == 0)
            throw Eccezione(ERR_FILE_READ, S_ERR_FILE_READ);
        
        /** Chiude il file */
        chiudi_file(testo);
    
    } catch (Eccezione e) {
        cerr << e;
        exit(e.getCodice());
    }
    
    return 0;
}
