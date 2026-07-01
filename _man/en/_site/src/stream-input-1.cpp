/** 
 * @file src/stream-input.cpp
 * Programma di esempio per la gestione dell'input da stream.
 */
 
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{    
    string stringa;
    
    /** Scrive un messaggio sullo schermo */
    cout << "Inserire una stringa: ";
    
    /** Legge una stringa da tastiera */
    cin >> stringa;

    /** La scrive sullo schermo */
    cout << stringa << endl;

    return 0;
}
