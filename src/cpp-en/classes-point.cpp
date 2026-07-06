/** 
 * @file classi-punto.cpp
 * Accesso ai dati membro della classe.
 */
 
#include <iostream>
#include <iomanip> 

using namespace std;

class Punto
{
public:             
    
    /** Dichiara i dati membro della classe */
    int _x, _y;

    /** 
     *  Le funzioni interne alla classe accedono ai
     *  dati membro con la sintassi ordinaria.
     */  
    Punto(int x, int y) {
        _x = x;
        _y = y;
    }
} ;

int main(int argc, char** argv) 
{
    /** Crea un oggetto di classe Punto */
    Punto p(5,6);       

    /** Assegna l'istanza della classe al puntatore ptr */
    Punto *ptr = &p ;   
    
    /** 
     *  Le funzioni esterne alla classe accedono ai
     *  dati membro tramite gli operatori di selezione.
     */  
    p._x    = 3 ;       // assegna un valore tramite l'oggetto
    ptr->_y = 2 ;       // assegna un valore tramite il puntatore
    
    //...
}
