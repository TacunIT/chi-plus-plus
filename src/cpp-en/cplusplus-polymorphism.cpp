/**
 * @file src/cplusplus-polymorphism.cpp
 * Example of class polymorphism.
 */

#include <iostream>
#include <ctime>

using namespace std;

typedef time_t Date;

typedef enum _sex {
    male = 'm',
    female = 'f'
} Sex;

class Animal {
private:
    string _breed;
    Sex    _sex;
public:
    virtual const char* getSpecies() const {
        return "";
    }
    const char getSex() const {
        return (char)_sex;
    }
    const char* getBreed() const {
        return _breed.c_str();
    }
    Animal() {}
    Animal(const char* breed, const Sex sex ) {
        _breed  = breed;
        _sex  = sex;
    }
};

ostream& operator << (ostream& os, const Animal& animal) {
    os  << "Species:" << animal.getSpecies() << "\t"
        << "Breed:"  << animal.getBreed()  << "\t"
        << "Sex:"  << animal.getSex()  << endl;
    return os;
}

class Horse : public Animal {
public:
    const char* getSpecies() const {
        return "Horse";
    }
    Horse() {}
    Horse(const char* breed, const Sex sex )
    : Animal(breed, sex ) {
    }
};

class Donkey : public Animal {
public:
    const char* getSpecies() const {
        return "Donkey";
    }
    Donkey() {}
    Donkey(const char* breed, const Sex sex )
    : Animal(breed, sex ) {
    }
};

class Mating {
private:
    Animal* _male;
    Animal* _female;
    Date    _day;
public:
    Mating(Animal* male, Animal* female) {
        _male = male;
        _female = female;
        time(&_day);
    }
    friend ostream& operator << (ostream& os, const Mating& mating) {
        os << "DATE: "    << asctime(localtime(&mating._day))
           << "MALE: " << *mating._male
           << "FEMALE: " << *mating._female;
           return os;
     };
};

int main()
{
    Animal* horse  = new Horse("Lipizzaner", male);
    Animal* mare   = new Horse("Maremmano", female);
    Animal* donkey = new Donkey("Amiata", male);
    Animal* jenny  = new Donkey("Sardinian", female);

    Mating foal(horse, mare);
    Mating jack(donkey, jenny);
    Mating mule(donkey, mare);
    Mating hinny(jenny, horse);

    cout << "FOAL\n"  << foal  << endl;
    cout << "JACK\n"    << jack    << endl;
    cout << "MULE\n"     << mule     << endl;
    cout << "HINNY\n" << hinny << endl;

    return 0;
}
