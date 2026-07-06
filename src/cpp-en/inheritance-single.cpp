/**
 * @file inheritance-single.cpp
 * Example of single inheritance.
 */

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum Water  { freshwater, saltwater };
enum Sex    { male, female };
enum Color  { red, blue, green, silver };

class Fish {
private:

    static int _n_fish;

protected:

    /** Private member data */
    Sex    _sex;
    float  _price;
    string _species;
    bool   _edible;

public:

    /** Inline class constructor */
    Fish(Sex sex, float price, const char* species)
    : _sex(sex), _price(price), _species(species)
    {
        _n_fish++;
    }

    /** Inline destructor */
    ~Fish() {
        _n_fish--;
    }

    /** Interface functions */
    void setSex(Sex sex);
    void setPrice(float price);
    void setSpecies(const char* species);

    /** Inline interface functions */
    string getSpecies() { return _species.c_str(); }
    float  getPrice() { return _price;  }
    Sex    getSex()  { return _sex; }
    bool   getEdible() { return _edible; }
    void   setEdible(bool edible) {
        _edible = edible;
    }

};

int Fish::_n_fish = 0 ;

class FoodFish : public Fish {
private:

    /** Private data of the class */
    time_t _catch_date;
    string _fishing_area;

public:

    /** Inline class constructor */
    FoodFish(Sex sex, float price, const char* species)
    : Fish(sex, price, species)
    {
        /** Hopefully.. */
        _edible = true;
    }

    //...
};

class AquariumFish : public Fish {
private:

    /** Private data of the class */
    time_t _purchase_date;
    Color  _color;
    Water  _water;

public:

    /** Inline class constructor */
    AquariumFish(Sex sex, float price, const char* species)
    : Fish(sex, price, species)
    {
    }

    //...
};
