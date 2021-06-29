/** 
 * @file pianeti-while-errore.cpp
 * Gestione dei Pianeti con errore nel ciclo while
 */
 
#include <iostream>
#include "pianeti.h"

using namespace std;

int main(int argc, char** argv)
{    
    int    p  = POS_MERCURIO;
    string nome;

    while (!(nome = nomePianeta(++p)).empty()) {
        cout << nome << endl;
    }
        
    return 0;
}
