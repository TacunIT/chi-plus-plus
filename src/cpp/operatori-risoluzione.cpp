/** 
 * @file _man/src/operatori-risoluzione.cpp
 * Utilizzo dell'operatore di risoluzione.
 */

#include <iostream>

using namespace std;

const char * Stringa = "Stringa globale" ;

int main(int argc, char** argv)
{   
    const char * Stringa = "Stringa locale" ;

	cout << Stringa   << endl ;
	cout << ::Stringa << endl ;

    return 0;
}
