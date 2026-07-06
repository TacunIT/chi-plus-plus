/**
 * @file classes-time-class.cpp
 * Handling the member data of a class.
 */

#include <iostream>
#include <iomanip>

using namespace std;

/** Declaration of the class */
class Time {
private:
    int _h;
    int _m;
    int _s;
public:
    Time(int h = 0, int m = 0, int s = 0);
};

/** Definition of the class's constructor */
Time::Time(int h, int m, int s)
: _h(h % 24), _m(m % 60), _s(s % 60)
{
}

/** The main function is not part of the class */
int main()
{
    Time now;

    /** This code will give an error */
    cout << setfill('0') << setw(2) << now._h << ":"
         << setfill('0') << setw(2) << now._m << ":"
         << setfill('0') << setw(2) << now._s << endl;

    return 0;
}
