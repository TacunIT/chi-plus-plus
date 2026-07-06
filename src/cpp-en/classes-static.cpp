/**
 * @file classes-static.cpp
 * Static functions and member data of a class.
 */

#include <iostream>

using namespace std;

/** Generic class with static members */
class Counter {
private:

    /** Defines the static data */
    static int _nInstances;

public:

    /** The constructor increments the number of instances */
    Counter() {
        _nInstances++;
    }

    /** Static interface function */
    static int nInstances() {
        return _nInstances;
    }
};

/** Initializes the static member  */
int Counter::_nInstances = 0;

int main()
{
    /** Creates the first instance of the class */
    Counter c1;

    /** Calls the static function from the object */
    cout << "From instance c1: " << c1.nInstances() << endl;

    /** Creates two more instances of the class */
    Counter c2, c3;

    /**
     * Calls the static function from the objects
     * and directly from the class
     */
    cout << "From instance c2: "<< c2.nInstances()         << endl;
    cout << "From instance c3: "<< c3.nInstances()         << endl;
    cout << "From the class : "<< Counter::nInstances() << endl;

    return 0;
}
