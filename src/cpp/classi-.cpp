/** 
 * @file classi-fiend.cpp
 * Funzione friend di una classe.
 */
 
#include <iostream>
#include <iomanip> 

using namespace std;

/** Dichiarazione della classe per gestire gli orarii */
class Orario {
private:

    /** Dati membro privati */
    int _h;
    int _m;
    int _s;

public:
    
    /** Costruttore della classe */
    Orario(int h = 0, int m = 0, int s = 0) ;

    /** Costruttore di copia inline */
    Orario(const Orario& o) 
    : _h(o._h), _m(o._m), _s(o._s) {
    }

    /** Distruttore della classe */
    ~Orario();

    /** Funzioni di scrittura */
    int setH(int h);
    int setM(int m);
    int setS(int s);

    /** Funzioni di lettura, inline nella dichiarazione */
    int getH() { return _h; }
    int getM() { return _m; }
    int getS() { return _s; }

    /** Dichiarazione di una funzione friend */
    friend int aggiornaMinuti(Orario& o, int m);

};

/** Definizione del costruttore della classe */
Orario::Orario(int h, int m, int s) 
: _h(h % 24), _m(m % 60), _s(s % 60) {
}

/** Definizione del distruttore della classe */
Orario::~Orario() {
}

/** 
 *  Definizione delle funzioni di scrittura, 
 *  anche loro, inline  
 */
inline int Orario::setH(int h) { 
    return _h = (h % 24); 
}

inline int Orario::setM(int m) { 
    return _m = (m % 60); 
}

inline int Orario::setS(int s) { 
    return _s = (s % 60); 
}


/** 
 * La funzione frend accede ai dati della classe 
 * in maniera diretta.
 */
int aggiornaMinuti(class Orario &o, int minuti) 
{
    /** Incrementa il numero dei minuti */
    o._m += minuti;
    
    /** Se necessario, incrementa le ore */
    if(o._m >= 60) {

        o._m -= 60;
        o._h += 1;
        
        /** Se necessario, passa al giorno dopo */
        if(o._h >= 24) {
            o._h -= 24;
        }
    }
    
    /** Torna il nuovo valore dei minuti */
    return o._m;
}

/**
 * La funzione main, accede ai dati della classe tramite
 * le funzioni di interfaccia.
 */
int main()
{    
    /** Crea un'istanza con il costruttre parametrizzato */
    Orario prima(47, 105, 60);

    /** Visualizza i valori iniziali dei dati */
    cout << setfill('0') << setw(2) << prima.getH() << ":" 
         << setfill('0') << setw(2) << prima.getM() << ":" 
         << setfill('0') << setw(2) << prima.getS() << endl;

    /** Crea una variabile con il costruttore di copia */
    Orario dopo = prima;
    
    /** Chiama la funzione friend per aggiornare i minuti */
    aggiornaMinuti(dopo, 15);
    
    /** Visualizza i valori dei dati modificati */
    cout << setfill('0') << setw(2) << dopo.getH() << ":" 
         << setfill('0') << setw(2) << dopo.getM() << ":" 
         << setfill('0') << setw(2) << dopo.getS() << endl;

         
    return 0;
}
