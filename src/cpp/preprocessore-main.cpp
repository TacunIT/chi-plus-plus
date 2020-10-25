#include <iostream>
#include<iomanip>

#define LANG_IT
#include "preprocessore-colore.h"
#undef LANG_IT

#ifdef LANG_IT
    #define  STR_BOOL   "booleano"
    #define  STR_CHAR   "carattere"
    #define  STR_INT    "intero"
    #define  STR_DEC    "decimale"
    #define  STR_ARRAY  "array"
    #define  STR_VERDE  "verde"
#else 
    #define  STR_BOOL   "boolean"
    #define  STR_CHAR   "character"
    #define  STR_INT    "integer"
    #define  STR_DEC    "decimal"
    #define  STR_ARRAY  "array"
    #define  STR_VERDE  "green"
#endif

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
    colore.coloreRgb.nome = STR_VERDE;     

    /** Mostra il valore delle variabili */
    cout << setw(10) << STR_BOOL  << ": " << booleano   << endl;
    cout << setw(10) << STR_CHAR  << ": " << carattere  << endl;
    cout << setw(10) << STR_INT   << ": " << intero     << endl;
    cout << setw(10) << STR_DEC   << ": " << decimale   << endl;
    cout << setw(10) << STR_ARRAY << ": " << array      << endl;
    
    /** Mostra il nome del colore */
    colore.nome_colore();
    
    return 0;
}
