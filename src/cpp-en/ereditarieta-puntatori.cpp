/** 
 * @file ereditarieta-puntatori.cpp
 * Gestione dei puntatori a classi derivate.
 */
 
#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    void getClass(){
        cout << "Persona" << endl;
    }
};

class Madre : virtual public Persona {
public:
    void getClass(){
        cout << "Madre" << endl;
    }
};
 
int main(int argc, char** argv) 
{
    Madre   * ptrM = new Madre;
    Persona * ptrP = ptrM ;
    ptrM->getClass() ;
    ptrP->getClass() ;
    return 0;
}
