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
    const char* getSpecie() const {
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
    os  << "Specie:" << animale.getSpecie() << ", "
        << "Razza:"  << animale.getRazza()  << ", "
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

class Accoppiamento {
private:
    Animale* _maschio;
    Animale* _femmina;
    Data     _giorno;
public:
    Accoppiamento(Animale* maschio, Animale* femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
    }
    friend ostream& operator << (ostream& os, const Accoppiamento& copula) {
        os << "Data: "    << asctime(localtime(&copula._giorno)) 
           << "MASCHIO: " << *copula._maschio 
           << "FEMMINA: " << *copula._femmina;
           return os;   
     };
};

int main()
{
    Data data;
    Animale* lui = new Cavallo("lipizzano", maschio);    
    Animale* lei = new Asino("amiatino", femmina);
    Accoppiamento copula(lui, lei);
    cout << copula << endl;
    return 0;               
}
