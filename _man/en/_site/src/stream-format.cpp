/** 
 * @file src/stream-format.cpp
 * Formattazione dell'I/O con gli stream.
 */
 
#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char** argv)
{    
    double d = 123.456789 ;

    /** Mostra i valori di default */
    cout << endl;
    cout << "Valori di default" << endl;
    cout << "  width:     "  << cout.width()        << endl;
    cout << "  precision: "  << cout.precision()    << endl; 	
    cout << "  fill:      '" << cout.fill()  << "'" << endl;	
    cout << "  output:    "  << d                   << endl;

    /** Modifica il formato e mostra il nuovo output */
    cout << endl;
    cout << "Modifica formato" << endl;
    cout << "  output:    "  ;
    cout.precision(4) ;
    cout.fill('#') ;
    cout.width(10) ;
    cout << d << endl;
    
    /** Mostra la persistenza dei valori */
    cout << endl;
    cout << "Valori correnti" << endl;
    cout << "  width:     "  << cout.width()        << endl;
    cout << "  precision: "  << cout.precision()    << endl; 	
    cout << "  fill:      '" << cout.fill()  << "'" << endl;	
    cout << "  output:    "  << d                   << endl;

    return 0;
}
