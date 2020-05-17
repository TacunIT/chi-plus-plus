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
            case red  : cout << "red"  ;   break;
            case green: cout << "green"; break;
            case blue : cout << "blue" ;  break;
        }
        cout << endl;
    }        
};

int main()
{    
    /** Dichiara una serie di variabili */
    bool    booleano = false;
    char    carattere = 'C';
    int     intero = 1234567890;
    float   decimale = 3.14;
    char    array[] = "abcdefghilmnopqrstuvz";
    RGB     enumerato = green;
    
    /** Crea un oggetto di tipo Colore */
    Colore  colore;    
    
    /** 
     * Assegna un valore ai dati della struttura coloreRgb 
     * all'interno dell'oggetto di tipo Colore.
     */
    colore.coloreRgb.valore = enumerato;   
    colore.coloreRgb.nome = "verde";     

    /** Mostra il valore delle variabili */
    cout << "booleano:"    << booleano   << endl;
    cout << "carattere:"   << carattere  << endl;
    cout << "intero:"      << intero     << endl;
    cout << "decimale:"    << decimale   << endl;
    cout << "array:"       << array      << endl;
    
    /** Mostra il nome del colore */
    colore.nome_colore();
    
    return 0;
}
