/** 
 * @file ereditarieta-classi-astratte.cpp
 * Gestione delle classi astratte.
 */
 
#include <iostream>
#include <string>

using namespace std;

enum Sesso { maschio, femmina, boh};
const char* Sessi[] = {"maschio", "femmina", "boh" };

class Mammifero
{
private:

    Sesso _sesso;

public:

    Mammifero(Sesso sesso = boh) 
    : _sesso(sesso) {
    }

    virtual void getSesso() {
        cout << Sessi[_sesso] << endl ;
    }    

    /** Funzione virtuale pura */
    virtual void getSpecie() = 0;
} ;

class Cane : public Mammifero
{ 
private:

    string _nome;

public:

    Cane(const char * nome, Sesso sesso) 
    : Mammifero(sesso), _nome(nome){
    }

    void getNome() {
        cout << _nome << endl ;
    }

    /** Definizione della funzione virtuale */
    virtual void getSpecie() {
        cout << "cane" << endl ;
    }    
};

int main()
{
    Cane mioCane("Scylla", femmina) ;
    Mammifero& cane = mioCane; 

    /** 
     * Accede alle funzioni della classe Cane
     * dall'istanza della classe.
     */
    mioCane.getSpecie();
    mioCane.getSesso();
    mioCane.getNome();
    
    /** 
     * Accede alle funzioni della classe Cane
     * dal puntatore alla classe Mammifero.
     */
    cane.getSpecie();
    cane.getSesso();
    
    return 0;
}
