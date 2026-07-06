/**
 *  @file src/cplusplus-template.cpp
 *  Example use of class templates.
 */

#include <iostream>
#include <ctime>
#include <cstring>
#include <list>

using namespace std;

/** Defines two new data types */
typedef time_t Date;
typedef enum _sex {
    male = 'm',
    female = 'f'
} Sex;

/** Defines a base class for handling animals */
class Animal {
private:
    string _breed;
    Sex    _sex;
public:
    /** Copy and parametric constructors */
    Animal() {}
    Animal(const char* breed, const Sex sex ) {
        _breed  = breed;
        _sex  = sex;
    }
    /** Pure virtual function: makes the class "abstract" */
    virtual const char* getSpecies() const {
        return "";
    }
    /** Interface functions */
    const char getSex() const {
        return (char)_sex;
    }
    const char* getBreed() const {
        return _breed.c_str();
    }
};

/** Stream output operator for the Animal class */
ostream& operator << (ostream& os, const Animal& animal) {
    os  << "Species:" << animal.getSpecies() << "\t"
        << "Breed:"  << animal.getBreed()  << "\t"
        << "Sex:"  << animal.getSex()
        << endl;
    return os;
}

/** Definition of the derived class Horse */
class Horse : public Animal {
public:
    /** Definition of the class's constructors */
    Horse() {}
    Horse(const char* breed, const Sex sex )
    : Animal(breed, sex ) {
    }
    /** Redefinition of the pure virtual function */
    const char* getSpecies() const {
        return "Horse";
    }
};

/** Definition of the derived class Donkey */
class Donkey : public Animal {
public:
    /** Definition of the class's constructor */
    Donkey() {}
    Donkey(const char* breed, const Sex sex )
    : Animal(breed, sex ) {
    }
    /** Redefinition of the pure virtual function */
    const char* getSpecies() const {
        return "Donkey";
    }
};

/** Definition of the Mating class */
class Mating {
private:
    Animal*  _male;
    Animal*  _female;
    Date     _day;
    string   _outcome;
    /**
    *   Private function for determining
    *   the outcome of the mating
    */
    void setOutcome() {
        if(strcmp(_male->getSpecies(),"Donkey") == 0) {
            if(strcmp(_female->getSpecies(),"Donkey") == 0) {
                _outcome = "donkey";
            } else {
                _outcome = "mule";
            }
        } else {
            if(strcmp(_female->getSpecies(),"Horse") == 0) {
                _outcome = "foal";
            } else {
                _outcome = "hinny";
            }
        }
    }
public:
    /** Class constructor */
    Mating(Animal* male, Animal* female) {
        _male = male;
        _female = female;
        time(&_day);
        setOutcome();
    }
    /** Output operator, "friend" of the Mating class */
    friend ostream& operator<<(ostream& os, const Mating& mating) {
        os << "DATE:    " << asctime(localtime(&mating._day))
           << "MALE: " << *mating._male
           << "FEMALE: " << *mating._female
           << "OUTCOME:   " << mating._outcome
           << endl;
           return os;
     };
};

int main()
{
    /**
     *  Creates the derived class objects
     *  and assigns them to base class pointers.
     */
    Animal* horse  = new Horse("Lipizzaner", male);
    Animal* mare = new Horse("Maremmano", female);
    Animal* donkey    = new Donkey("Amiata", male);
    Animal* jenny    = new Donkey("Sardinian", female);

    /** Creates a list using a template class */
    list<Mating> matings;

    /** Adds Mating class objects to the list */
    matings.push_back(Mating(horse, mare));
    matings.push_back(Mating (donkey, jenny));
    matings.push_back(Mating (donkey, mare));
    matings.push_back(Mating (horse, jenny));

    /** Displays the contents of the list */
    list<Mating>::iterator it;
    for (it=matings.begin(); it!=matings.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
