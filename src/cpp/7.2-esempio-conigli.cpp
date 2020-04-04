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
    string _specie;
    Sesso  _sesso;
public:
    Animale() {}
    Animale(const char* specie, const char* razza, const Sesso sesso ) {
        _specie = specie;
        _razza  = razza;
        _sesso  = sesso;
    }
    friend ostream& operator << (ostream& os, const Animale& animale) {
        os  << "Specie:" << animale._specie      << ", "
            << "Sesso:"  << (char)animale._sesso << ", "
            << "Razza:"  << animale._razza       << endl;
        return os;   
    }
};

class Coniglio : public Animale {
public:
    Coniglio() {}
    Coniglio(const char* razza, const Sesso sesso )
    : Animale("coniglio", razza, sesso ) { 
    }
};

class Accoppiamento {
private:
    Coniglio _maschio;
    Coniglio _femmina;
    Data     _giorno;
public:
    Accoppiamento(const Coniglio& maschio, const Coniglio& femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
    }
    friend ostream& operator << (ostream& os, const Accoppiamento& copula) {
        os << "Data:"     << asctime(localtime(&copula._giorno)) 
           << "MASCHIO: " << copula._maschio 
           << "FEMMINA: " << copula._femmina 
           << endl;
           return os;   
     };
};

int main()
{
    Data data;
    Coniglio Jessica("angora", femmina);
    Coniglio Roger("martora", maschio);    
    Accoppiamento copula(Roger, Jessica);
    cout << copula << endl;
    return 0;               
}
