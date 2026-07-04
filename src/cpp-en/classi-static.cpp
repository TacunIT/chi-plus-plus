/** 
 * @file classi-static.cpp
 * Funzioni e dati membro statici di una classe.
 */
 
#include <iostream>

using namespace std;

/** Classe generica con membri statici */
class Contatore {
private:

    /** Definisce il dato statico */
    static int _nIstanze;     

public:
    
    /** Il costruttore incrementa il numero di istanze */
    Contatore() {
        _nIstanze++;
    }
    
    /** Funzione di interfaccia statica */
    static int nIstanze() {  
        return _nIstanze;
    }
};

/** Inizializza il membro statico  */ 
int Contatore::_nIstanze = 0;

int main()
{    
    /** Crea la prima istanza della classe */
    Contatore c1;

    /** Richiama la funzione statica dall'oggetto */
    cout << "Da istanza c1: " << c1.nIstanze() << endl;

    /** Crea altre due istanze della classe */
    Contatore c2, c3;
   
    /** 
     * Richiama la funzione statica dagli oggetti 
     * e direttamente dalla classe
     */
    cout << "Da istanza c2: "<< c2.nIstanze()         << endl;
    cout << "Da istanza c3: "<< c3.nIstanze()         << endl;
    cout << "Dalla classe : "<< Contatore::nIstanze() << endl;
    
    return 0;
}
