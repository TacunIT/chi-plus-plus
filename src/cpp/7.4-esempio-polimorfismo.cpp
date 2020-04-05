#include <iostream>
#include <ctime>

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
        << "Sesso:"  << animale.getSesso()  << endl;
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
public:
    Monta(Animale* maschio, Animale* femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
    }
    friend ostream& operator << (ostream& os, const Monta& copula) {
        os << "DATA: "    << asctime(localtime(&copula._giorno)) 
           << "MASCHIO: " << *copula._maschio 
           << "FEMMINA: " << *copula._femmina;
           return os;   
     };
};

int main()
{
    Animale* cavallo  = new Cavallo("lipizzano", maschio);    
    Animale* giumenta = new Cavallo("maremmano", femmina);    
    Animale* asino    = new Asino("amiatino", maschio);
    Animale* asina    = new Asino("sardo", femmina);

    Monta puledro(cavallo, giumenta);
    Monta ciuco(asino, asina);
    Monta mulo(asino, giumenta);
    Monta bardotto(asina, cavallo);

    cout << "PULEDRO\n"  << puledro  << endl;
    cout << "CIUCO\n"    << ciuco    << endl;
    cout << "MULO\n"     << mulo     << endl;
    cout << "BARDOTTO\n" << bardotto << endl;

    return 0;               
}
