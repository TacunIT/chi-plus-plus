/**
 * @file inheritance-virtual-base-classes.cpp
 * Handling virtual base classes.
 */

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    void getClass(){
        cout << "Person" << endl;
    }
};

class Dad : public virtual Person {
};

class Mom : virtual public Person {
};

class Son : public Dad, public Mom {
};

int main(int argc, char** argv)
{
    Son cain;
    cain.getClass();
    return 0;
}
