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

    /** Costruttore di copia */
    Orario(const Orario& o) ;

    /** Funzioni di lettura inline */
    inline int getH() { return _h; }
    inline int getM() { return _m; }
    inline int getS() { return _s; }

    /** Funzioni di scrittura inline */
    inline int setH(int h) { return _h = (h % 24); }
    inline int setM(int m) { return _m = (m % 60); }
    inline int setS(int s) { return _s = (s % 60); }

};

/** Definizione del costruttore della classe */
Orario::Orario(int h, int m, int s) 
: _h(h), _m(m), _s(s) {
}

/** Definizione del costruttore di copia */
Orario::Orario(const Orario& o) 
: _h(o._h), _m(o._m), _s(o._s) {
}

/**
 * La funzione main, adesso, non accede più direttamente 
 * ai dati della classe 
 */
int main()
{    
    Orario ora;

    /** Visualizza i valori iniziali dei dati */
    cout << setfill('0') << setw(2) << ora.getH() << ":" 
         << setfill('0') << setw(2) << ora.getM() << ":" 
         << setfill('0') << setw(2) << ora.getS() << endl;
    
    ora.setH(47);
    ora.setM(105);
    ora.setS(60);
    
    /** Visualizza i valori dei dati modificati */
    cout << setfill('0') << setw(2) << ora.getH() << ":" 
         << setfill('0') << setw(2) << ora.getM() << ":" 
         << setfill('0') << setw(2) << ora.getS() << endl;

    /** Crea una variabile con il costruttore di copia */
    Orario now = ora;

    /** Visualizza i valori della nuova variabile */
    cout << setfill('0') << setw(2) << now.getH() << ":" 
         << setfill('0') << setw(2) << now.getM() << ":" 
         << setfill('0') << setw(2) << now.getS() << endl;
         
    return 0;
}
