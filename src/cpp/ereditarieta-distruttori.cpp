/** 
 * @file ereditarieta-distruttori.cpp
 * Gestione dei distruttori nelle classi derivate.
 */
 
#include <iostream>
#include <string>

using namespace std;

/** Definiamo una classe base */
class Padre {
public:
    ~Padre() ;
} ;

/** Definiamo delle classi derivate. */
class Figlio : public Padre {
public:
    ~Figlio() ;
};

class Nipote : public Figlio {
public:
    ~Nipote() ;
};

int main(int argc, char** argv) 
{
    /** Creiamo un array di puntatori di classe base. */
    Padre * dinastia[3] ;     

    /** Assegnamo delle istanze delle tre classi ai puntatori */
    dinastia[0]= new Padre  ; 
    dinastia[1]= new Figlio ;
    dinastia[2]= new Nipote ;

    /** Facciamo qualcosa con i nostri oggetti.. */

    /** ..e poi li eliminiamo */
    delete dinastia[0] ; 
    delete dinastia[1] ;  
    delete dinastia[2] ;  
}
