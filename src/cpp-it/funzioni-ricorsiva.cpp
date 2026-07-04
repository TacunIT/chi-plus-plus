/** 
 * @file /src/funzioni-ricorsiva.cpp
 * Esempio di funzione ricorsiva.
 */

#include <iostream>
#include <iomanip> 

using namespace std;

/** Dichiarazione della funzione ricorsiva */
long fattoriale(int n);

/** Funzione main prima della definizione */
int main(int argc, char** argv)
{   
    int n = 9;
    cout << n << "! = " << fattoriale(n) << endl;
    return 0;
}

/** Definizione della funzione ricorsiva */
long fattoriale(int n)
{
    long fatt = 1;
    if(n > 1) {
        fatt = n * fattoriale(n-1);
    }
    return fatt;
}
