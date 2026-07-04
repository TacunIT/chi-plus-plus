/** 
 * @file ereditarieta-classi-base-virtuali.cpp
 * Gestione delle classi base virtuali.
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

class Padre : public virtual Persona {
};

class Madre : virtual public Persona {
};
 
class Figlio : public Padre, public Madre {
};
 
int main(int argc, char** argv) 
{
    Figlio caino;
    caino.getClass();
    return 0;
}
