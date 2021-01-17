/** 
 * @file funzioni-stipendio-errore.cpp
 * Funzione che genera un errore di compilazione.
 */
#include <iostream> 

/**
 * La funzione main richiama la funzione raddoppiaStipendio,
 * ma il compilatore ancora non sa che esiste: errore.
 */
int main(int argc, char** argv)
{        
    std::cout << raddoppiaStipendio(1500) << std::endl;    
    return 0;
}

/** 
 * Definizione della funzione raddoppiaStipendio DOPO
 * il suo utilizzo da parte della funzione main. 
 */
float raddoppiaStipendio(float stipendio)
{
    return stipendio * 2;
}
