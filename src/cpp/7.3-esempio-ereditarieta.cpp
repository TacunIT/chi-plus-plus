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
    string _specie;
    string _razza;
    Sesso  _sesso;
public:
    const char* getSpecie() const {
        return _specie.c_str(); 
    } 
    const char getSesso() const {        
        return (char)_sesso;
    } 
    const char* getRazza() const {
        return _razza.c_str();
    }
    Animale() {}
    Animale(const char* specie, const char* razza, const Sesso sesso ) {
        _specie = specie;
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
    Cavallo() {}
    Cavallo(const char* razza, const Sesso sesso )
    : Animale("Cavallo", razza, sesso ) { 
    }
};

class Monta {
private:
    Cavallo _maschio;
    Cavallo _femmina;
    Data     _giorno;
public:
    Monta(Cavallo& maschio, Cavallo& femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
    }
    friend ostream& operator << (ostream& os, const Monta& copula) {
        os << "Data: "     << asctime(localtime(&copula._giorno)) 
           << "MASCHIO: " << copula._maschio 
           << "FEMMINA: " << copula._femmina;
           return os;   
     };
};

int main()
{
    Cavallo lui("lipizzano", maschio);    
    Cavallo lei("maremmano", femmina);
    Monta monta(lui, lei);
    cout << monta << endl;
    return 0;               
}
