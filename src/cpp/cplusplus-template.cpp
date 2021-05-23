/** 
 *  @file src/cplusplus-template.cpp
 *  Esempio utlizzo dei template di classi.
 */

#include <iostream>
#include <ctime>
#include <cstring>
#include <list>

using namespace std;

/** Definisce due nuovi tipi di dato */
typedef time_t Data;
typedef enum _sesso {
    maschio = 'm',
    femmina = 'f'
} Sesso;

/** Definisce una classe base per la gestione degli animali */
class Animale {
private:
    string _razza;
    Sesso  _sesso;
public:
    /** Costruttori di copia e parametrico */
    Animale() {}
    Animale(const char* razza, const Sesso sesso ) {
        _razza  = razza;
        _sesso  = sesso;
    }
    /** Funzione virtuale pura: rende la classe "astratta" */
    virtual const char* getSpecie() const {
        return ""; 
    } 
    /** Funzioni di interfaccia */
    const char getSesso() const {        
        return (char)_sesso;
    } 
    const char* getRazza() const {
        return _razza.c_str();
    }
};

/** Operatore di output su stream per la classe Animale */
ostream& operator << (ostream& os, const Animale& animale) {
    os  << "Specie:" << animale.getSpecie() << "\t"
        << "Razza:"  << animale.getRazza()  << "\t"
        << "Sesso:"  << animale.getSesso()  
        << endl;
    return os;   
}

/** Definizione della classe derivata Cavallo */
class Cavallo : public Animale {
public:
    /** Definizione dei costruttori della classe */
    Cavallo() {}
    Cavallo(const char* razza, const Sesso sesso )
    : Animale(razza, sesso ) { 
    }
    /** Ridefinizione della funzione virtuale pura */
    const char* getSpecie() const {
        return "Cavallo"; 
    }     
};

/** Definizione della classe derivata Cavallo */
class Asino : public Animale {
public:
    /** Definizione del costruttore della classe */
    Asino() {}
    Asino(const char* razza, const Sesso sesso )
    : Animale(razza, sesso ) { 
    }
    /** Ridefinizione della funzione virtuale pura */
    const char* getSpecie() const {
        return "Asino"; 
    }     
};

/** Definizione della classe Monta */
class Monta {
private:
    Animale* _maschio;
    Animale* _femmina;
    Data     _giorno;
    string   _esito;
    /** Funzione privata per la definizione dell'esito della monta */
    void setEsito() {
        if(strcmp(_maschio->getSpecie(),"Asino") == 0) {
            if(strcmp(_femmina->getSpecie(),"Asino") == 0) {
                _esito = "asino";
            } else {
                _esito = "mulo";
            } 
        } else {        
            if(strcmp(_femmina->getSpecie(),"Cavallo") == 0) {
                _esito = "puledro";
            } else {
                _esito = "bardotto";
            } 
        }
    }
public:
    /** Costruttore della classe */
    Monta(Animale* maschio, Animale* femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
        setEsito();
    }
    /** Operatore di output, "friend" della classe Monta */
    friend ostream& operator << (ostream& os, const Monta& copula) {
        os << "DATA:    " << asctime(localtime(&copula._giorno)) 
           << "MASCHIO: " << *copula._maschio 
           << "FEMMINA: " << *copula._femmina
           << "ESITO:   " << copula._esito
           << endl;
           return os;   
     };
};

int main()
{
    /** 
     *  Crea gli oggetti di classe derivata  
     *  e li assegna a puntatori della classe base.
     */
    Animale* cavallo  = new Cavallo("lipizzano", maschio);    
    Animale* giumenta = new Cavallo("maremmano", femmina);    
    Animale* asino    = new Asino("amiatino", maschio);
    Animale* asina    = new Asino("sardo", femmina);

    /** Crea una lista con una classe template */
    list<Monta> monte;

    /** Associa alla lista degli oggetti di classe Monta */
    monte.push_back(Monta(cavallo, giumenta)); 
    monte.push_back(Monta (asino, asina));       
    monte.push_back(Monta (asino, giumenta));     
    monte.push_back(Monta (cavallo, asina));

    /** Mostra il contenuto della lista */
    for (list<Monta>::iterator it=monte.begin(); it!=monte.end(); it++) {
        cout << *it << endl;
    }

    return 0;               
}
