/**
 * @file src/stream-format.cpp
 * Formatting I/O with streams.
 */

#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    double d = 123.456789 ;

    /** Shows the default values */
    cout << endl;
    cout << "Default values" << endl;
    cout << "  width:     "  << cout.width()        << endl;
    cout << "  precision: "  << cout.precision()    << endl;
    cout << "  fill:      '" << cout.fill()  << "'" << endl;
    cout << "  output:    "  << d                   << endl;

    /** Changes the format and shows the new output */
    cout << endl;
    cout << "Changed format" << endl;
    cout << "  output:    "  ;
    cout.precision(4) ;
    cout.fill('#') ;
    cout.width(10) ;
    cout << d << endl;

    /** Shows the persistence of the values */
    cout << endl;
    cout << "Current values" << endl;
    cout << "  width:     "  << cout.width()        << endl;
    cout << "  precision: "  << cout.precision()    << endl;
    cout << "  fill:      '" << cout.fill()  << "'" << endl;
    cout << "  output:    "  << d                   << endl;

    return 0;
}
