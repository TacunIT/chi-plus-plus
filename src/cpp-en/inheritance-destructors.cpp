/**
 * @file inheritance-destructors.cpp
 * Handling destructors in derived classes.
 */

#include <iostream>
#include <string>

using namespace std;

/** Let's define a base class */
class Dad {
public:
    ~Dad() ;
} ;

/** Let's define some derived classes. */
class Son : public Dad {
public:
    ~Son() ;
};

class Grandson : public Son {
public:
    ~Grandson() ;
};

int main(int argc, char** argv)
{
    /** Let's create an array of base class pointers. */
    Dad * dynasty[3] ;

    /** Let's assign instances of the three classes to the pointers */
    dynasty[0]= new Dad  ;
    dynasty[1]= new Son ;
    dynasty[2]= new Grandson ;

    /** Let's do something with our objects.. */

    /** ..and then delete them */
    delete dynasty[0] ;
    delete dynasty[1] ;
    delete dynasty[2] ;
}
