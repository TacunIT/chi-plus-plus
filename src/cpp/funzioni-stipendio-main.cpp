/** 
 * @file funzioni-stipendio-main.cpp
 * Funzione main del programma con file oggetto separati.
 */
#include <iostream> 

/** 
 * Dichiarazione della funzione raddoppiaStipendio. 
 * L'ho messa qui per semplicità: di solito, le dichiarazioni
 * si trovano in un file di include separato.
 */
float raddoppiaStipendio(float stipendio);

/**
 * La funzione main richiama la funzione raddoppiaStipendio,
 * che è definita in un altro file sorgente.
 */
int main(int argc, char** argv)
{        
    std::cout << raddoppiaStipendio(1500) << std::endl;    
    return 0;
}
