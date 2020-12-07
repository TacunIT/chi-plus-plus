/** 
 * @file pianeti.h
 * Costanti e funzione per la gestione dei Pianeti.
 */

#ifndef _PIANETI
#define _PIANETI 1
 
using namespace std;

/** Dichiarazione delle costanti */
#define POS_NESSUNO -1
#define POS_ERRORE   0
#define POS_MERCURIO 1
#define POS_VENERE   2
#define POS_TERRA    3
#define POS_MARTE    4
#define POS_GIOVE    5
#define POS_SATURNO  6
#define POS_URANO    7
#define POS_NETTUNO  8
#define POS_PLUTONE  9

/** Dichiarazione delle funzioni */
bool mostraPianeta(int pianeta);
string nomePianeta(int posizione);

#endif /* _PIANETI */
