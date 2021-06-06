/** 
 * @file src/preprocessore-hashtag.cpp
 * Esempii di macro-istruzioni del precompilatore.
 */

#include <iostream>

using namespace std;
 
/** Definisce la macro-istruzione */
#define FUNZIONE(nome, parametro) int fnz_##nome() { return parametro; }

/** 
*   Durante la precompilazone, questa macro 
*   sarà sosituita dall'istruzione:
*       
*     int fnz_macro(12) { return 12; }
*/
FUNZIONE(macro, 12)
 
/** 
*   Definisce una macro che stampa un testo a video:
*/
#define OUTPUT(testo) cout << testo << endl;
 
/** 
*   Definisce una macro che unisce la stringa "Pippo"
*   al parametro ricevuto in input:
*/
#define PIPPO "Pippo"
#define APPENDI(nome) PIPPO # nome
 
int main()
{
    /** 
    *   La funzione fnz_macro ora non esiste, ma esisterà 
    *   al termine della pre-compilazione del codice:
    */
    cout << fnz_macro() << endl;
 
    /** Stampa una stringa a video usando le altre due macro */
    OUTPUT(APPENDI(Pluto));               
}
