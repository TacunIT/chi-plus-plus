/** 
 * @file pianeti.cpp
 * @version 1.0
 * Funzione per la gestione dei Pianeti.
 */

#include <iostream>
#include "pianeti.h"

/**
 *  mostraPianeta 
 *  Visualizza il nome di un pianeta, data la sua posizione.
 *  @param  int  pianeta Posizione del pianeta.
 *  @return bool esiste  true se il pianeta esiste.
 */
bool mostraPianeta(int pianeta)
{    
    bool esiste = true;
    
    switch( pianeta ) {
        case POS_ERRORE:   
            cout << "Valore non valido"; 
            break;
        case POS_MERCURIO: 
            cout << "Mercurio";          
            break;
        case POS_VENERE:   
            cout << "Venere";            
            break;
        case POS_TERRA:    
            cout << "Terra";             
            break;
        case POS_MARTE:    
            cout << "Marte";             
            break;
        case POS_GIOVE:    
            cout << "Giove";             
            break;
        case POS_SATURNO:  
            cout << "Saturno";           
            break;
        case POS_URANO:    
            cout << "Urano";             
            break;          
        case POS_NETTUNO:  
            cout << "Nettuno";           
            break;          
        case POS_PLUTONE:  
            cout << "Plutone";           
            break;
        default:
            esiste = false;
            cout << "Inserire un valore da: " 
                 << POS_MERCURIO 
                 << " a " 
                 << POS_PLUTONE;                    
    } 
    
    return esiste;
}
