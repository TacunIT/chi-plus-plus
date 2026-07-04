/** 
 * @file src/polimorfismo-rot13.cpp
 * Trasformazione di una stringa con una funzione.
 */

#include <string>
#include <cctype>
#include <iostream>
#include <functional>

using namespace std;

/** 
*   Funzione che converte i caratteri di una stringa in rot13  
*   Il ROT13 è un algoritmo di cifratura piuttosto banale, 
*   perché incrementa di 13 il valore di ciascun carattere. 
*   Non è un algoritmo realmente sicuro, però, perché per 
*   decifrare il testo crittografato basta crittografarlo 
*   di nuovo.  
*/
unsigned char rot13(unsigned char c) 
{ 
    unsigned char rot = c;
    if (isalpha(c)) {
        rot = ((tolower(c) - 'a') < 14) ? c + 13 : c - 13;
    }
    return rot;
}

int main ()
{
    string pp("PippoPluto"); 

    /** Elabora la stringa con la funzione transform */
    transform(
               pp.begin()   // inizio del container da modificare
             , pp.end()     // fine del container da modificare
             , pp.begin()   // container di output
             , rot13        // funzione da applicare
             );

    cout << pp << endl; 

    /** Ripetendo l'operazione, il testo torna normale. */
    transform(
               pp.begin()   
             , pp.end()     
             , pp.begin()   
             , rot13        
             );

    cout << pp << endl; 
    
    return 0;
}
