/** 
 * @file src/polimorfismo-classe-template.cpp
 * Esempio di classe template.
 */

#include <iostream>

using namespace std;

/**
*   Definisce una classe che gestisce coppie 
*   di coordinate.
*/
template<class T>
class Coord {
private:
    /** Dati membro con tipo variabile */
    T _x, _y; 
public:
    /** Costruttore con tipo di parametri variabile */
    Coord(const T x, const T y) 
    : _x(x), _y(y) {        
    }
    friend ostream& operator << (ostream& o, const Coord& c) {
        o << c._x << ',' << c._y ;
        return o;
    }
};

int main ()
{         
    /** Istanza con coordinate geografiche */
    Coord<double> obelisco(41.903219, 12.458157);
    
    /** Istanza con coordinate schermo */
    Coord<int>    pixel(821, 134);
    
    cout << "Obelisco:" << obelisco << endl;    
    cout << "Pixel:   " << pixel    << endl;    
    
    return 0;
}
