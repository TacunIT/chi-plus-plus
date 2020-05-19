#include <iostream>
#include <bitset>
#include <iomanip> 

using namespace std;

/** Definisce il tipo di dato byte di otto bit */
typedef unsigned char byte;
typedef short int duebyte;

int main()
{    
    /** Crea un array di 80 valori binarii */
    byte valori[] = { 
          0b01000011, 0b00100111, 0b01101000, 0b01100001
        , 0b01101110, 0b01101110, 0b01101111, 0b00100000 
        , 0b01100110, 0b01101111, 0b01110010, 0b01110011
        , 0b01100101, 0b00100000, 0b01110100, 0b01110101
        , 0b01110100, 0b01110100, 0b01100101, 0b00100000
        , 0b01100101, 0b00100000, 0b01100100, 0b01110101
        , 0b01100101, 0b00100000, 0b01101100, 0b01100001
        , 0b00100000, 0b01110011, 0b01110100, 0b01100101
        , 0b01110011, 0b01110011, 0b01100001, 0b00100000
        , 0b01100101, 0b01110100, 0b11100000, 0b00100000
        , 0b00001010, 0b01001010, 0b01100101, 0b00100000
        , 0b01100110, 0b01101001, 0b01101111, 0b01110010
        , 0b01101001, 0b01110011, 0b01100011, 0b01100101
        , 0b00100000, 0b01100100, 0b01100101, 0b01101110
        , 0b01110100, 0b01110010, 0b01101111, 0b00100000
        , 0b01100001, 0b01110010, 0b00100000, 0b01100011
        , 0b01101111, 0b01110010, 0b01100101, 0b00100000
        , 0b00100111, 0b01101110, 0b00100000, 0b01101001
        , 0b01101100, 0b01101100, 0b01110101, 0b01110011
        , 0b01101001, 0b01101111, 0b01101110, 0b01100101 
    };

    /** 
     * Crea un puntatore gli assegna come valore 
     * lìindirizzo dell'inizio dell'array 
     */
    byte * p1 = valori;
    
    /** 
     * Sposta il puntatore per tutta la lunghezza dell'array,
     * mostrando per ciascun byte il suo valore binario, il
     * suo valore convertito in decimale e la lettera del      
     * set ASCII corrispondente a quel valore.
     */
    for(int i = 0; i < sizeof(valori); i++) {
        cout << setw(4)  << i
             << setw(18) << bitset<8>(*p1) 
             << setw(6)  << (int)*p1 
             << setw(4)  << (char) *p1 << endl;
        p1++;
    }
    
    cout << endl;
    
    duebyte * p2 = (duebyte*)valori;
    
    /** 
     * Sposta il puntatore per tutta la lunghezza dell'array,
     * mostrando per ciascun byte il suo valore binario, il
     * suo valore convertito in decimale e la lettera del      
     * set ASCII corrispondente a quel valore.
     */
    for(int i = 0; i < sizeof(valori) / 2; i++) {
        cout << setw(4)  << i
             << setw(18) << bitset<16>(*p2) 
             << setw(6)  << (short)*p2 
             << setw(4)  << (char) *p2 << endl;
        p2++;
    }
    return 0;
}
