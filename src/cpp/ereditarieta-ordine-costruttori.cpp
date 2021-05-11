/** 
 * @file ereditarieta-ordine-costruttori.cpp
 * Ordine di chiamata dei costruttori nell'ereditarierà multipla.
 */
 
#include <iostream>
#include <string>
#include <ctime> 

using namespace std;

class Mamma {
public:
    Mamma() {
        cout << "costruttore Mamma" << endl;
    }
};

class Padre {
public:
    Padre() {
        cout << "costruttore Padre" << endl;
    }
};
 
class Figlio
: public Padre, public Mamma {
public:
    Figlio() {
        cout << "costruttore Figlio" << endl;
    }
};

class Figlia
: public Mamma, public Padre {
public:
    Figlia() {
        cout << "costruttore Figlia" << endl;
    }
};

 
int main(int argc, char** argv) 
{
    Figlio Hansel;
    Figlia Gretel;

    return 0;
}
