/**
 * @file classes-fish.cpp
 * Definition of the Fish class.
 */

#include <iostream>

using namespace std;

/**
 *  Declaration of the class: idea
 */
class Fish {
private:

    /** Private member data */
    string _species;
    bool   _edible;

public:

    /** Inline class constructor */
    Fish(const char* species, bool edible)
    : _species(species), _edible(edible)
    {
    }

    /** Inline copy constructor */
    Fish(const Fish& f) {
        this->_species = f._species;
        this->_edible  = f._edible;
    }

    /** Inline destructor */
    ~Fish() {
    }

    /** Interface functions */
    const char* getSpecies() { return _species.c_str(); }
    bool isEdible()          { return _edible;           }

};


/**
 *  Instance of the class: form
 */
int main()
{
    Fish fish("seabass", true);

    cout << fish.getSpecies() << ": "
         << (fish.isEdible() ? "yes" : "no")
         << endl;

    return 0;
}
