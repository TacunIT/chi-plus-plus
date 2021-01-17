/** 
 * @file funzioni-stipendio-main.cpp
 * Funzione main del programma con compilazione separata dei file oggetto.
 */
#include <iostream> 

/** 
 * Dichiarazione della funzione raddoppiaStipendio. 
 * Può stare o qui o in un file di include.
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
