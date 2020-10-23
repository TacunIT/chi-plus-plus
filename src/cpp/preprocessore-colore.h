
#ifndef _CLASS_COLORE
#define _CLASS_COLORE 1

#define  RGB_RED    0xFF0000
#define  RGB_GREEN  0x00FF00
#define  RGB_BLUE   0x0000FF

#define  STR_RGB    "coloreRGB"
#define  STR_RED    "red"
#define  STR_GREEN  "green"
#define  STR_BLUE   "blue"

#include <iostream>

using namespace std;

/** Definisce un tipo di dato enumerato di nome RGB */
enum RGB { red = RGB_RED, green = RGB_GREEN, blue = RGB_BLUE };

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
        cout << STR_RGB;
        switch(coloreRgb.valore) {
            case red  : cout << STR_RED  ; break;
            case green: cout << STR_GREEN; break;
            case blue : cout << STR_BLUE ; break;
        }
        cout << endl;
    }        
};

#endif /* _CLASS_COLORE */
