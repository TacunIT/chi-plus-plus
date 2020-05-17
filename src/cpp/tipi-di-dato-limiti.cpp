#include <iostream>
#include <iomanip> 
#include <limits>

using namespace std;

/**
 * Funzione template che mostra la dimensione e i 
 * valori minimi e massimi per un tipo di dato.
 */
template<typename T>
void dimensione()
{
    cout << sizeof(T) << " bytes,"
         << setw(4)   << "da:"   
         << setw(21)  << numeric_limits<T>::min()
         << setw(4)   << "a:"    
         << setw(21)  << numeric_limits<T>::max() 
         << endl;
}

int main()
{    
    /** Variazione della dimensione e dei valori del tipo int */
    cout << setw(16) << "int: "; 
    dimensione<int>();
    cout << setw(16) << "unsigned int: "; 
    dimensione<unsigned int>();
    cout << setw(16) << "short int: "; 
    dimensione<short int>();
    cout << setw(16) << "unsigned short: "; 
    dimensione<unsigned short>();
    cout << setw(16) << "long int: "; 
    dimensione<long int>();
    cout << setw(16) << "unsigned long: "; 
    dimensione<unsigned long>();
    
    return 0;
}
