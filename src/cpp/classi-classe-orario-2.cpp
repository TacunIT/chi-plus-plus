/** 
 * @file classi-classe-orario-1.cpp
 * Gestione dei dati membro di una classe.
 */
 
#include <iostream>
#include <iomanip> 

using namespace std;

/** Dichiarazione di una classe per gestire gli orarii */
class Orario {
protected:

    /** Dati membro privati */
    int _h;
    int _m;
    int _s;

public:
    
    /** Costruttore della classe */
    Orario(int h = 0, int m = 0, int s = 0) ;

    /** Funzioni di lettura inline */
    inline int getOre()     { return _h; }
    inline int getMinuti()  { return _m; }
    inline int getSecondi() { return _s; }

    /** Funzioni di scrittura inline */
    int setOre(int h)    { return _h = (h % 24); }
    int setMinuti(int m) { return _m = (m % 60); }
    int setSecondi(int s){ return _s = (s % 60); }

};

/** Definizione del costruttore della classe */
Orario::Orario(int h, int m, int s) 
: _h(h), _m(m), _s(s) {
}

/**
 * La funzione main, adesso, non accede più direttamente 
 * ai dati della classe 
 */
int main()
{    
    Orario ora;

    /** Visualizza i valori iniziali dei dati */
    cout << setfill('0') << setw(2) << ora.getOre()     << ":" 
         << setfill('0') << setw(2) << ora.getMinuti()  << ":" 
         << setfill('0') << setw(2) << ora.getSecondi() << endl;
    
    ora.setOre(47);
    ora.setMinuti(105);
    ora.setSecondi(60);
    
    /** Visualizza i valori dei dati modificati */
    cout << setfill('0') << setw(2) << ora.getOre()     << ":" 
         << setfill('0') << setw(2) << ora.getMinuti()  << ":" 
         << setfill('0') << setw(2) << ora.getSecondi() << endl;
         
    return 0;
}
