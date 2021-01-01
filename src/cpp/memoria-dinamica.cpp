/** 
 * @file memoria-dinamica.cpp
 * Gestione dinamica della memoria.
 */
 
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{    
    /** 
    * Qui dovrebbe controllare che le stringhe ci siano.. 
    */
   
    /** Legge la lunghezza delle due stringhe */        
    size_t len1 = strlen(argv[1]);
    size_t len2 = strlen(argv[2]);

    /** 
     * Alloca un'area di memoria grande quanto le due
     * stringhe più un carattere di spazio e un
     * carattere terminatore.
     */   
    size_t lunghezza = len1 + len2 + 2; 
    char* stringa = new char[lunghezza];

    /** Copia le stringhe nell'area di memoria */
    sprintf(stringa, "%s %s", argv[1], argv[2]);

    /**
     * Mostra l'indirizzo dell'area di memoria,
     * la sua dimensione e il suo contenuto
     */
    cout << (void*)stringa << endl;
    cout << lunghezza      << endl; 
    cout << stringa        << endl;
    
    /** Libera la memoria allocata */
    delete[] stringa;
    
    return 0;
}
