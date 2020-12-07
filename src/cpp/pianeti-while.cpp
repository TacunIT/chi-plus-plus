/** 
 * @file pianeti-while.cpp
 * Gestione dei Pianeti con istruione while.
 */
 
#include <iostream>
#include "pianeti.h"

using namespace std;

string mostraPianeta(int posizione)
{    
    string nome;
    
    switch( posizione ) {
        case POS_MERCURIO: 
            nome =  "Mercurio";          
            break;
        case POS_VENERE:   
            nome =  "Venere";            
            break;
        case POS_TERRA:    
            nome =  "Terra";             
            break;
        case POS_MARTE:    
            nome =  "Marte";             
            break;
        case POS_GIOVE:    
            nome =  "Giove";             
            break;
        case POS_SATURNO:  
            nome =  "Saturno";           
            break;
        case POS_URANO:    
            nome =  "Urano";             
            break;          
        case POS_NETTUNO:  
            nome =  "Nettuno";           
            break;          
        case POS_PLUTONE:  
            nome =  "Plutone";           
            break;
        case POS_ERRORE:   
        default:
            cerr << "Inserire un valore da: " 
                 << POS_MERCURIO 
                 << " a " 
                 << POS_PLUTONE;      
    } 
    
    return nome;
}

int main(int argc, char** argv)
{    
    int    p = POS_MERCURIO;
    string nome ;
    
    /** Elenca tutti i Pianeti del Sistema Solare */
    while (!(nome = mostraPianeta(p)).empty()) {
        cout << p++ << ": " << nome << endl;
    }
        
    return 0;
}
