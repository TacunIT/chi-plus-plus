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

class Babbo {
public:
    Babbo() {
        cout << "costruttore Babbo" << endl;
    }
};
 
class Figlio
: public Babbo, public Mamma {
public:
    Figlio() {
        cout << "costruttore Figlio" << endl;
    }
};

class Figlia
: public Mamma, public Babbo {
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
