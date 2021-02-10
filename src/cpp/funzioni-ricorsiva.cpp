/** 
 * @file /src/funzioni-ricorsiva.cpp
 * Esempio di funzione ricorsiva.
 */

#include <iostream>
#include <iomanip> 

using namespace std;

/** Dichiarazione della funzione ricorsiva */
void ricorsiva(int n);

/** Funzione main prima della definizione */
int main(int argc, char** argv)
{   
    int n = 9;
    ricorsiva(n);
    cout << endl;
    return 0;
}

/** Definizione della funzione ricorsiva */
void ricorsiva(int n)
{
    /** Richiama sé stessa pr n volte */
    if(n > 0) {
        ricorsiva(n-1);
        cout << setw(2) << n;
    }
}
