
#ifndef _CLASS_COLORE
#define _CLASS_COLORE 1

#include <iostream>

using namespace std;

/** Definisce un tipo di dato enumerato di nome RGB */
enum RGB { red = 0xFF0000, green = 0x00ff00, blue = 0x0000ff };

/** Definisce una struttura che contiene un colore RGB e un nome */
struct ColoreRGB {
    RGB  valore;
    const char* nome;        
};

/** 
 * Definisce la classe Colore, che contiene un coloreRGB 
 * e una funzione che ne mostra il nome.
 */
class Colore {
public:
    ColoreRGB coloreRgb;        
    void nome_colore() {
        cout << "coloreRGB:";
        switch(coloreRgb.valore) {
            case red  : cout << "red"  ; break;
            case green: cout << "green"; break;
            case blue : cout << "blue" ; break;
        }
        cout << endl;
    }        
};

#endif /* _CLASS_COLORE */
