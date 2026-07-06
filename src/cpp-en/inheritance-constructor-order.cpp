/**
 * @file inheritance-constructor-order.cpp
 * Order of constructor calls in multiple inheritance.
 */

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Mom {
public:
    Mom() {
        cout << "Mom constructor" << endl;
    }
};

class Dad {
public:
    Dad() {
        cout << "Dad constructor" << endl;
    }
};

class Son
: public Dad, public Mom {
public:
    Son() {
        cout << "Son constructor" << endl;
    }
};

class Daughter
: public Mom, public Dad {
public:
    Daughter() {
        cout << "Daughter constructor" << endl;
    }
};


int main(int argc, char** argv)
{
    Son Hansel;
    Daughter Gretel;

    return 0;
}
