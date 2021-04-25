/** 
 * @file ereditarieta-pesce.cpp
 * Definizione della classe Pesce e delle sue classi derivate.
 */
 
#include <iostream>
#include <string>
#include <ctime> 

using namespace std;

enum Acqua  { dolce, salata };
enum Sesso  { maschio, femmina };
enum Colore { rosso, blu, verde, argento };

class Pesce {
protected:
    
    /** Dati membro privati */
    Sesso  _sesso;
    float  _prezzo;
    string _specie;
    bool   _commestibile;

public:

    /** Costruttore della classe inline */
    Pesce(Sesso sesso, float prezzo, const char* specie) 
    : _sesso(sesso), _prezzo(prezzo), _specie(specie)
    {
    }
    
    /** Distruttore inline */
    ~Pesce() { 
    }

    /** Funzioni di interfaccia */
    void setSesso(Sesso sesso);
    void setPrezzo(float prezzo);
    void setSpecie(const char* specie);

    /** Funzioni di interfaccia inline */
    string getSpecie() { return _specie.c_str(); }
    float  getPrezzo() { return _prezzo;  }
    Sesso  getSesso()  { return _sesso; }
    bool   getCommestibile() { return _commestibile; }
    void   setCommestibile(bool commestibile) { 
        _commestibile = commestibile; 
    }

};

class PesceAlimentare : public Pesce {
private:
    
    /** Dati privati della classe */
    time_t _data_cattura;  
    string _area_pesca; 

public:

    /** Costruttore della classe inline */
    PesceAlimentare(Sesso sesso, float prezzo, const char* specie) 
    : Pesce(sesso, prezzo, specie)
    {
        /** Auspicabilmente.. */
        _commestibile = true;
    }

    ...
};

class PesceAcqario : public Pesce {
private:
    
    /** Dati privati della classe */
    time_t _data_acquisto;  
    Colore _colore;
    Acqua  _acqua;

public:
    
    /** Costruttore della classe inline */
    PesceAcqario(Sesso sesso, float prezzo, const char* specie) 
    : Pesce(sesso, prezzo, specie)
    {
    } 
    
    ...
};
