#include <iostream>
#include <functional>

using namespace std;

template<int d,int t> class Unit
{
    double value;
public:
    Unit(double n)
    {
        value = n;
    }
    Unit<d,t> operator+(Unit<d,t> n)
    {
        return Unit<d,t>(value + n.value);
    }
    Unit<d,t> operator-(Unit<d,t> n)
    {
        return Unit<d,t>(value - n.value);
    }
    Unit<d,t> operator*(double n)
    {
        return Unit<d,t>(value * n);
    }
    Unit<d,t> operator/(double n)
    {
        return Unit<d,t>(value / n);
    }
};

#define Distance Unit<1,0>
#define Time     Unit<0,1>
#define Second   Time(1.0)
#define Meter    Distance(1.0)

void foo()
{
   Distance moved1 = 5 * Meter;
   Distance moved2 = 10 * Meter;
   Time time1 = 10 * Second;
   Time time2 = 20 * Second;
   if ((moved1 / time1) == (moved2 / time2))
       printf("Same speed!");
}
