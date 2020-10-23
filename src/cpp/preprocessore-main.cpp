#include <iostream>

#define LANG_IT
#include "colore.h"

using namespace std;

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
