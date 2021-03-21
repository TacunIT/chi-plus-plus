/** 
 * @file classi-struttura-orario.cpp
 * Gestione dei dati membro di una struct.
 */
 
#include <iostream>
#include <iomanip> 

using namespace std;

/** Dichiarazione di una struttura per gestire un orario */
struct Orario {
    int h;
    int m;
    int s;
};

/** Funzione per l'incremento dei minuti */
void aggiornaMinuti(struct Orario &o, int minuti) 
{
    /** Incrementa il numero dei minuti */
    o.m += minuti;
    
    /** Se necessario, incrementa le ore */
    if(o.m >= 60) {

        o.m -= 60;
        o.h += 1;
        
        /** Se necessario, passa al giorno dopo */
        if(o.h >= 24) {
            o.h -= 24;
        }
    }
}

/*  Funzione cialtrona per l'incremento dei minuti */
void incrementa_m(struct Orario &o, int minuti) 
{
    o.m += minuti;
}

int main()
{    
    struct Orario ora;

    /** Definisce dei valori iniziali prossimi al cambio di data */
    ora.h = 23;
    ora.m = 45;
    ora.s = 00;

    /** Visualizza i valri iniziali */
    cout << setfill('0') << setw(2) << ora.h << ":" 
         << setfill('0') << setw(2) << ora.m << ":" 
         << setfill('0') << setw(2) << ora.s << endl;

    /** Richiama la funzione di aggiornamento */
    aggiornaMinuti(ora, 20);
    
    /** Visualizza i valori dopo l'aggiornamento */
    cout << setfill('0') << setw(2) << ora.h << ":" 
         << setfill('0') << setw(2) << ora.m << ":" 
         << setfill('0') << setw(2) << ora.s << endl;

    /** Reimposta i valori iniziali */
    ora.h = 23;
    ora.m = 45;
    ora.s = 00;

    /** Richiama la funzione cialtrona */
    incrementa_m(ora, 20);
    
    /** Visualizza i valori dopo l'aggiornamento */
    cout << setfill('0') << setw(2) << ora.h << ":" 
         << setfill('0') << setw(2) << ora.m << ":" 
         << setfill('0') << setw(2) << ora.s << endl;

    
    return 0;
}
