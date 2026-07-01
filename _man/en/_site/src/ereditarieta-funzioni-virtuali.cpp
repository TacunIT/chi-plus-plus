/** 
 * @file ereditarieta-funzioni-virtuali.cpp
 * Gestione delle funzioni virtuali.
 */
 
#include <iostream>

using namespace std;

class Persona {
public:
    virtual void getClass(){
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
