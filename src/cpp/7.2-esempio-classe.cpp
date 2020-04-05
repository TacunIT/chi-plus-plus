#include <iostream>
#include <ctime>

using namespace std;

typedef time_t Data;

typedef enum _sesso {
    maschio = 'm',
    femmina = 'f'
} Sesso;

class Cavallo {
private:
    Sesso  _sesso;
    string _razza;
public:
    const char* getSpecie() const {
        return "cavallo"; 
    } 
    const char getSesso() const {        
        return (char)_sesso;
    }
    const char* getRazza() const {
        return _razza.c_str();
    }
    Cavallo() {}
    Cavallo(const char* razza, Sesso sesso ) {
        _razza  = razza;
        _sesso  = sesso;
    }
};

ostream& operator << (ostream& os, const Cavallo& Cavallo) {
    os  << "Specie:" << Cavallo.getSpecie() << ", "
        << "Sesso:"  << Cavallo.getSesso()  << ", "
        << "Razza:"  << Cavallo.getRazza()  << endl;
    return os;   
}


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
        os << "DATA: "    << asctime(localtime(&copula._giorno)) 
           << "MASCHIO: " << copula._maschio 
           << "FEMMINA: " << copula._femmina 
           << endl;
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
