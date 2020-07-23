#include <iostream>

#define NO_ERRORI     0
#define NO_PARAMETRI  1

int main(int argc, char** argv)
{    
    int errore = NO_ERRORI;
    
    /** Se c'è solo il nome del programma, errore */
    if(argc < 2) {
        std::cerr << "Specificare almeno un parametro!" << std::endl;
        return NO_PARAMETRI;
    }

    /** Stampa tutti i parametri ricevuti */
    for(int p=0; p < argc; p++) {
        std::cout << *argv++ << std::endl;        
    }

    return 0;
}
