/**
 * @file classes-time-struct.cpp
 * Handling the member data of a struct.
 */

#include <iostream>
#include <iomanip>

using namespace std;

/** Declaration of a structure to handle a time */
struct Time {
    int h;
    int m;
    int s;
};

/** Function to increment the minutes */
void updateMinutes(struct Time &t, int minutes)
{
    /** Increments the number of minutes */
    t.m += minutes;

    /** If needed, increments the hours */
    if(t.m >= 60) {

        t.m -= 60;
        t.h += 1;

        /** If needed, moves on to the next day */
        if(t.h >= 24) {
            t.h -= 24;
        }
    }
}

/*  Sloppy function to increment the minutes */
void increment_m(struct Time &t, int minutes)
{
    t.m += minutes;
}

int main()
{
    struct Time now;

    /** Sets initial values close to the date change */
    now.h = 23;
    now.m = 45;
    now.s = 00;

    /** Displays the initial values */
    cout << setfill('0') << setw(2) << now.h << ":"
         << setfill('0') << setw(2) << now.m << ":"
         << setfill('0') << setw(2) << now.s << endl;

    /** Calls the update function */
    updateMinutes(now, 20);

    /** Displays the values after the update */
    cout << setfill('0') << setw(2) << now.h << ":"
         << setfill('0') << setw(2) << now.m << ":"
         << setfill('0') << setw(2) << now.s << endl;

    /** Resets the initial values */
    now.h = 23;
    now.m = 45;
    now.s = 00;

    /** Calls the sloppy function */
    increment_m(now, 20);

    /** Displays the values after the update */
    cout << setfill('0') << setw(2) << now.h << ":"
         << setfill('0') << setw(2) << now.m << ":"
         << setfill('0') << setw(2) << now.s << endl;


    return 0;
}
