/** 
 * @file funzioni-argomenti.cpp
 * Esempio di gestione degli argomenti di una funzione.
 */

#include <iostream>
#include <iomanip> 
#include <fstream> 

using namespace std;

/**
*   Chiamata per valore: tutto quello che succede qui
*   alle variabili a e b non influenza le variabili 
*   x e y della funzione chiamante.
*/
void perValore(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

/**
*   Chiamata per reference: tutto quello che succede qui
*   alle variabili a e b è come se fosse fatto alle variabili
*   x e y della funzione chiamante.
*/
void perRiferimento(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

/**
*   Chiamata per puntatore: anche qui, quello che succede 
*   alle variabili a e b avviene anche alle variabili x e y 
*   della funzione chiamante.
*/
void perPuntatore(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int main(int argc, char** argv)
{        
    int  x = 11; int  y = 22;    
    cout << setw(20) << "Valore iniziale: x=" << x << ", y=" << y << endl;
    
    int* p = &x;
    int& r = x;
    
    cout << "p:" << p << ",r=" << r << endl;

    /**
    *   Passaggio per valore: l'argomento della chiamata
    *   a funzione è il valore delle variabili x e y:
    */
    perValore(x,y);
    cout << setw(20) << "perValore: x=" << x << ", y=" << y << endl;

    /**
    *   Passaggio per reference: l'argomento della chiamata
    *   a funzione sono le variabili x e y, ma la funzione 
    *   utiizzerà il loro indirizzo, non il loro valore:
    */
    perRiferimento(x,y);
    cout << setw(20) << "perRiferimento: x=" << x << ", y=" << y << endl;

    /**
    *   Passaggio per puntatore: l'argomento della chiamata
    *   è esplicitamente l'indirizzo delle variabili x e y:
    */
    perPuntatore(&x,&y);
    cout << setw(20) << "perPuntatore: x=" << x << ", y=" << y << endl;
    
    return 0;
}
