/**
 * @file classes-god.cpp
 * Declaration of the God class.
 */

#include <iostream>
#include <list>


using namespace std;

// Abstract class to be used as a base
// for all the elements of Creation.
class Creature {
public:
   // Pure virtual verification function.
   virtual bool isGood() = 0;

};

// Derived classes for handling the
// elements of Creation.
class Sea    : public Creature {
    bool isGood() { return true; };
};
class Man    : public Creature {
    bool isGood();
};
class Woman  : public Creature {};
class Father : public Man      {};
class Son    : public Man      {};
class People : public list<Creature> {};

class  {
private:

    // Member functions for generating the elements
    // of Creation, accessible only to the class.
    Creature* createLight();
    Creature* createStars();
    Creature* createWaterEarth();
    Creature* createPlants();
    Creature* createSunMoon();
    Creature* createAnimals();

    // Functions for generating humans.
    Man&   createMan();
    Woman& createWoman(Man& adam);

    // Break for the seventh day.
    void shabbat();

    // Interface functions with humans.
    bool populateEden(Man& adam, Woman& eve);
    bool printCommandments(ostream& tablets);
    bool checkFaith(Father& abraham, Son& isaac);
    bool splitWaters(Sea& redSea, People& hebrews);

protected:

    // Member function also accessible to
    // child classes.
    bool giveLife(Man& lazarus);

public:

     // Public member function.
     // Returns the number of prayers to be recited.
    int forgiveSins(Creature* believer);

} God;
