/** 
 * @file classi-pesce.cpp
 * Definizione della classe Pesce.
 */
 
#include <iostream>
#include <iomanip> 

using namespace std;

/**
 *  Dichiarazione della classe: idea
 */
class Pesce {
private:

    /** Dati membro privati */
    string _specie;
    bool   _commestibile;
    
public:
    
    /** Costruttore della classe inline */
    Pesce(const char* specie, bool commestibile) 
    : _specie(specie), _commestibile(commestibile)
    {
    }
    
    /** Costruttore di copia inline */
    Pesce(const Pesce& p) {
        this->_specie       = p._specie;
        this->_commestibile = p._commestibile;
    }

    /** Distruttore inline */
    ~Pesce() { 
    }

    /** Funzioni di interfaccia */
    const char* getSpecie() { return _specie.c_str(); }
    bool isCommestibile()   { return _commestibile;   }

};


/**
 *  Istanza della classe: forma
 */
int main()
{             
    Pesce pesce("spigola", true);
    
    cout << pesce.getSpecie() << ": "
         << (pesce.isCommestibile() ? "sì" : "no")
         << endl;
     
    return 0;
}
