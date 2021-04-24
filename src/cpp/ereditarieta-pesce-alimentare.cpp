/** 
 * @file ereditarieta-pesce-alimentare.cpp
 * Definizione della classe Pesce per utilizzo alimentare.
 */
 
#include <iostream>
#include <ctime> 

using namespace std;

class Pesce {
private:

    /** Dati membro privati */
    bool   _commestibile;
    string _specie;
    int    _peso;
    float  _prezzo;
    time_t _data_cattura;  
    string _area_pesca; 
    
public:
    
    /** Costruttore della classe inline */
    Pesce(const char* specie, int peso) 
    : _specie(specie), _peso(peso)
    {
        /** Auspicabilmente.. */
        _commestibile = true;
    }
    
    /** Distruttore inline */
    ~Pesce() { 
    }

    /** Funzioni di interfaccia */
    void setPeso(int peso);
    void setPrezzo(float prezzo);
    void setCattura(short anno, short mese, short giorno);
    void setAreaPesca(const char* area_pesca);

    /** Funzioni di interfaccia inline */
    const char* getAreaPesca()   { return _area_pesca.c_str(); }
    const char* getSpecie()      { return _specie.c_str(); }
    bool        isCommestibile() { return _commestibile; }
    time_t      getDataCattura() { return _data_cattura; }
    int         getPeso()        { return _prezzo; }
    float       getPrezzo()      { return _peso; }
    
};
