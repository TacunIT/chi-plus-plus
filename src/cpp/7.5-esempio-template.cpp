#include <iostream>
#include <ctime>
#include <cstring>
#include <list>

using namespace std;

typedef time_t Data;

typedef enum _sesso {
    maschio = 'm',
    femmina = 'f'
} Sesso;

class Animale {
private:
    string _razza;
    Sesso  _sesso;
public:
    virtual const char* getSpecie() const {
        return ""; 
    } 
    const char getSesso() const {        
        return (char)_sesso;
    } 
    const char* getRazza() const {
        return _razza.c_str();
    }
    Animale() {}
    Animale(const char* razza, const Sesso sesso ) {
        _razza  = razza;
        _sesso  = sesso;
    }
};

ostream& operator << (ostream& os, const Animale& animale) {
    os  << "Specie:" << animale.getSpecie() << "\t"
        << "Razza:"  << animale.getRazza()  << "\t"
        << "Sesso:"  << animale.getSesso()  
        << endl;
    return os;   
}

class Cavallo : public Animale {
public:
    const char* getSpecie() const {
        return "Cavallo"; 
    }     
    Cavallo() {}
    Cavallo(const char* razza, const Sesso sesso )
    : Animale(razza, sesso ) { 
    }
};

class Asino : public Animale {
public:
    const char* getSpecie() const {
        return "Asino"; 
    }     Asino() {}
    Asino(const char* razza, const Sesso sesso )
    : Animale(razza, sesso ) { 
    }
};

class Monta {
private:
    Animale* _maschio;
    Animale* _femmina;
    Data     _giorno;
    string   _esito;
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
    Monta(Animale* maschio, Animale* femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
        setEsito();
    }
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
    Animale* cavallo  = new Cavallo("lipizzano", maschio);    
    Animale* giumenta = new Cavallo("maremmano", femmina);    
    Animale* asino    = new Asino("amiatino", maschio);
    Animale* asina    = new Asino("sardo", femmina);
    list<Monta> monte;
    monte.push_back(Monta(cavallo, giumenta)); 
    monte.push_back(Monta (asino, asina));       
    monte.push_back(Monta (asino, giumenta));     
    monte.push_back(Monta (cavallo, asina));
    monte.reverse();
    for (list<Monta>::iterator it=monte.begin(); it!=monte.end(); it++) {
        cout << *it << endl;
    }
    return 0;               
}
