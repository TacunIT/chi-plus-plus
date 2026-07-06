/**
 * @file inheritance-multiple.cpp
 * Example of multiple inheritance.
 */

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum Water  { freshwater, saltwater };
enum Sex    { male, female, unknown};
enum Color  { red, blue, green, silver };

/**
 * Declaration of the Item class
 */
class Item {
private:

    static int _n_items;

protected:

    /** Private member data */
    float  _price;

public:

    /** Inline class constructor */
    Item(float price = 0.0)
    : _price(price)
    {
        _n_items++;
        cout << "Item constructor" << endl;
    }

    /** Inline destructor */
    ~Item() {
        _n_items--;
        cout << "Item destructor" << endl;
    }

    /** Interface functions */
    void setPrice(float price);

    /** Static interface function */
    static int getInstances() { return _n_items; }

    /** Inline interface functions */
    float getPrice()     { return _price;     }
    const char* getType() { return "item";  }
};

/** Initializes the static member data */
int Item::_n_items = 0 ;

/**
 * Declaration of the Fish class
 */
class Fish {
private:

    static int _n_fish;

protected:

    /** Private member data */
    Sex    _sex;
    string _species;
    bool   _edible;

public:

    /** Inline class constructor */
    Fish(Sex sex = unknown, const char* species = "unknown")
    : _sex(sex), _species(species)
    {
        _n_fish++;
        cout << "Fish constructor" << endl;
    }

    /** Inline destructor */
    ~Fish() {
        _n_fish--;
        cout << "Fish destructor" << endl;
    }

    /** Interface functions */
    void setSex(Sex sex);
    void setSpecies(const char* species);

    /** Static interface function */
    static int getInstances()      { return _n_fish; }

    /** Inline interface functions */
    string getSpecies()       { return _species.c_str(); }
    Sex    getSex()        { return _sex; }
    bool   getEdible() { return _edible; }
    void   setEdible(bool edible) {
        _edible = edible;
    }
};

/** Initializes the static member data */
int Fish::_n_fish = 0 ;

/**
 * Declaration of the FoodFish class
 */
class FoodFish
: public Fish, public Item {
private:

    /** Private data of the class */
    time_t _catch_date;
    string _fishing_area;

public:

    /** Inline class constructor */
    FoodFish(Sex sex, float price, const char* species)
    : Item(price)
    , Fish(sex, species)
    {
        /** Hopefully.. */
        _edible = true;
        cout << "FoodFish constructor" << endl;
    }

    /** Inline destructor */
    ~FoodFish() {
        cout << "FoodFish destructor" << endl;
    }

    /** Override of the base class function */
    const char* getType() { return "food fish"; }

    //...
};

class AquariumFish
: public Item, public Fish {
private:

    /** Private data of the class */
    time_t _purchase_date;
    Color  _color;
    Water  _water;

public:

    /** Inline class constructor */
    AquariumFish(Sex sex, float price, const char* species)
    : Fish(sex, species)
    , Item(price)
    {
        cout << "AquariumFish constructor" << endl;
    }

    /** Inline destructor */
    ~AquariumFish() {
        cout << "AquariumFish destructor" << endl;
    }

    /** Override of the base class function */
    const char* getType() { return "aquarium fish"; }

    //...
};

int main(int argc, char** argv)
{
    /** Creates the two instances of the classes */
    AquariumFish fish1(male, 2.5, "Paracheirodon");
    FoodFish fish2(female, 25.4, "Dicentrarchus labrax");

    /** Calls the interface functions */
    cout <<  fish1.getType() << ": " << fish1.getSpecies()
         << endl;
    cout <<  fish2.getType() << ": " << fish2.getSpecies()
         << endl;

    /** Calls the base class function */
    cout << "base class: " << fish1.Item::getType() << endl;

    /** Calls the static interface functions */
    cout <<  "items created: " << Item::getInstances()
         << endl;
    cout <<  "fish created:  " << Fish::getInstances()
         << endl;

    return 0;
}
