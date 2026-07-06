/**
 * @file inheritance-virtual-functions.cpp
 * Handling virtual functions.
 */

#include <iostream>

using namespace std;

class Person {
public:
    virtual void getClass(){
        cout << "Person" << endl;
    }
};

class Mom : virtual public Person {
public:
    void getClass(){
        cout << "Mom" << endl;
    }
};

int main(int argc, char** argv)
{
    Mom    * ptrM = new Mom;
    Person * ptrP = ptrM ;
    ptrM->getClass() ;
    ptrP->getClass() ;
    return 0;
}
