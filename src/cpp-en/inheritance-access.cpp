/**
 * @file inheritance-access.cpp
 * Access to base class members from derived classes.
 */

/** Base class, public member data */
struct Mom {
    int a;
};

/** Derived class as struct: data public by default */
struct Daughter : Mom {
    int b;
};

/** Derived class as class: data private by default */
class Son : Mom {
    int c;
};

/** Generic function, not a friend of the classes */
void func(Daughter& daughter, Son& son)
{
    daughter.a++;
    son.a++;
}
