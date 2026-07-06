/**
 * @file src/polymorphism-cast.cpp
 * Handling explicit conversion.
 */

using namespace std;

class Fraction
{
private:

    int _num ;
    int _den ;

public:

    /** Constructor with integer parameters */
    Fraction(int n, int d = 1)
    : _num(n), _den(d) {}

    /**
     * Constructor with a floating-point parameter.
     * The definition is fairly complex, I'll spare you the details.
     */
    Fraction(double d) ;

    /** Overload of the cast-to-int operator */
    operator int () {
        return _num / _den ;
    }

    /** Overload of the cast-to-double operator */
    operator double() {
        return (double) _num / (double) _den ;
    }

    /** Overload of the addition and subtraction operators */
    friend Fraction operator+ (Fraction f1, Fraction f2);
    friend Fraction operator- (Fraction f1, Fraction f2);

};
