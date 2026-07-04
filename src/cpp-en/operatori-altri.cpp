/** 
 * @file operatori-altri.cpp
 * Altri operatori del C++.
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{        
    int     a = 9;
    int     b = 4;

    /** Converte un valore intero in char */
    char    c = char(a * b);

    /** Assegna a t il valore più alto fra a e b */
    int     t = (a > b) ? a : b;

    /** Salva nel puntatore p l'indirizzo di memoria di a */
    int*    p = &a;    

    /** Calcola la dimensione di un intero */
    size_t sa = sizeof(a);

    /** Calcola la dimensione di un puntatore a intero */
    size_t sp = sizeof(p);

    /** Mostra l'indirizzo della variabile a */
    cout << "&a: " << p  << endl;

    /** Mostra la dimensione delle variabili a e p */
    cout << "sa: " << sa << endl;
    cout << "sp: " << sp << endl;

    /** Mostra il risultato dell'operazione ternaria */
    cout << "t : " << t  << endl;

    /** Il codice ASCII 36 corrisponde alla lettera $x\ */
    cout << "c : " << c  << endl;
    
    cout << endl;

    return 0;
}
