/** 
 * @file ereditarieta-pesce-articolo.cpp
 * Esempio di ereditarierà multipla.
 */
 
#include <iostream>
#include <string>
#include <ctime> 

using namespace std;

enum Acqua  { dolce, salata };
enum Sesso  { maschio, femmina };
enum Colore { rosso, blu, verde, argento };

/** 
 * Dichiarazione della classe Articolo 
 */
class Articolo {
private:

    static int _n_articoli;
                        
protected:
    
    /** Dati membro privati */
    float  _prezzo;

public:

    /** Costruttore della classe inline */
    Articolo(float prezzo) 
    : _prezzo(prezzo)
    {
        _n_articoli++;
        cout << "costruttore Articolo" << endl;
    }
    
    /** Distruttore inline */
    ~Articolo() { 
        _n_articoli--;
        cout << "distruttore Articolo" << endl;       
    }

    /** Funzioni di interfaccia */
    void setPrezzo(float prezzo);

    /** Funzione di interfaccia statica */
    static int getIstanze() { return _n_articoli; }

    /** Funzioni di interfaccia inline */
    float getPrezzo()     { return _prezzo;     }
    const char* getTipo() { return "articolo";  }
};

/** Inizializza il dato membro statico */            
int Articolo::_n_articoli = 0 ;

/** 
 * Dichiarazione della classe Pesce 
 */
class Pesce {
private:
            
    static int _n_pesci;
                        
protected:
    
    /** Dati membro privati */
    Sesso  _sesso;
    string _specie;
    bool   _commestibile;

public:

    /** Costruttore della classe inline */
    Pesce(Sesso sesso, const char* specie) 
    : _sesso(sesso), _specie(specie)
    {
        _n_pesci++;        
        cout << "costruttore Pesce" << endl;
    }
    
    /** Distruttore inline */
    ~Pesce() { 
        _n_pesci--;
        cout << "distruttore Pesce" << endl;
    }

    /** Funzioni di interfaccia */
    void setSesso(Sesso sesso);
    void setSpecie(const char* specie);

    /** Funzione di interfaccia statica */
    static int getIstanze()      { return _n_pesci; }

    /** Funzioni di interfaccia inline */
    string getSpecie()       { return _specie.c_str(); }
    Sesso  getSesso()        { return _sesso; }
    bool   getCommestibile() { return _commestibile; }
    void   setCommestibile(bool commestibile) { 
        _commestibile = commestibile; 
    }
};

/** Inizializza il dato membro statico */            
int Pesce::_n_pesci = 0 ;

/** 
 * Dichiarazione della classe PesceAlimentare 
 */
class PesceAlimentare 
: public Pesce, public Articolo {
private:
    
    /** Dati privati della classe */
    time_t _data_cattura;  
    string _area_pesca; 

public:

    /** Costruttore della classe inline */
    PesceAlimentare(Sesso sesso, float prezzo, const char* specie) 
    : Articolo(prezzo)
    , Pesce(sesso, specie)
    {
        /** Auspicabilmente.. */
        _commestibile = true;
        cout << "costruttore PesceAlimentare" << endl;
    }

    /** Distruttore inline */
    ~PesceAlimentare() { 
        cout << "distruttore PesceAlimentare" << endl;
    }

    /** Ridefinizione della funzione della classe base */
    const char* getTipo() { return "pesce alimentare"; }

    //...
};

class PesceAcquario 
: public Articolo, public Pesce {
private:
    
    /** Dati privati della classe */
    time_t _data_acquisto;  
    Colore _colore;
    Acqua  _acqua;

public:
    
    /** Costruttore della classe inline */
    PesceAcquario(Sesso sesso, float prezzo, const char* specie) 
    : Pesce(sesso, specie)
    , Articolo(prezzo)
    {
        cout << "costruttore PesceAcquario" << endl;
    } 

    /** Distruttore inline */
    ~PesceAcquario() { 
        cout << "distruttore PesceAcquario" << endl;
    }

    /** Ridefinizione della funzione della classe base */
    const char* getTipo() { return "pesce acquario"; }
    
    //...
};

int main(int argc, char** argv) 
{
    /** Crea le due istanze delle classi */
    PesceAlimentare pesce2(femmina, 25.4, "Dicentrarchus labrax");
    PesceAcquario pesce1(maschio, 2.5, "Paracheiredon");

    /** Richiama le funzioni di interfaccia */
    cout <<  pesce1.getTipo() << ": " << pesce1.getSpecie() 
         << endl;
    cout <<  pesce2.getTipo() << ": " << pesce2.getSpecie() 
         << endl;

    /** Richiama la funzione della classe base */
    cout << "classe base: " << pesce1.Articolo::getTipo() << endl;

    /** Richiama le funzioni di interfaccia statiche */
    cout <<  "articoli creati: " << Articolo::getIstanze() 
         << endl;
    cout <<  "pesci creati:    " << Pesce::getIstanze() 
         << endl;
    
    return 0;
}
