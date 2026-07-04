/** 
 * @file tipi-di-dato-reference.cpp
 * Utilizzo delle reference.
 */
 
#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{    
    /** Definisce una variabile di tipo int */
    int  v = 10;     

    /** Definisce una reference alla variabile v */
    int& r = v;    

    /** I valori di v e r sono identici perché r è un'alias di v */
    cout << "valori iniziali: v=" << v << ", r=" << r << endl;

    /** Modifica il valore della variabile r */
    r = 20;

    /** Il valore di v sarà modificato di conseguenza */
    cout << "valori finali:   v=" << v << ", r=" << r << endl;
    
    return 0;
}
