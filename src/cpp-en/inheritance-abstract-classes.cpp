/**
 * @file inheritance-abstract-classes.cpp
 * Handling abstract classes.
 */

#include <iostream>
#include <string>

using namespace std;

enum Sex { male, female, unknown};
const char* Sexes[] = {"male", "female", "unknown" };

class Mammal
{
private:

    Sex _sex;

public:

    Mammal(Sex sex = unknown)
    : _sex(sex) {
    }

    virtual void getSex() {
        cout << Sexes[_sex] << endl ;
    }

    /** Pure virtual function */
    virtual void getSpecies() = 0;
} ;

class Dog : public Mammal
{
private:

    string _name;

public:

    Dog(const char * name, Sex sex)
    : Mammal(sex), _name(name){
    }

    void getName() {
        cout << _name << endl ;
    }

    /** Definition of the virtual function */
    virtual void getSpecies() {
        cout << "dog" << endl ;
    }
};

int main()
{
    Dog myDog("Scylla", female) ;
    Mammal& dog = myDog;

    /**
     * Accesses the Dog class's functions
     * from the class instance.
     */
    myDog.getSpecies();
    myDog.getSex();
    myDog.getName();

    /**
     * Accesses the Dog class's functions
     * from the pointer to the Mammal class.
     */
    dog.getSpecies();
    dog.getSex();

    return 0;
}
