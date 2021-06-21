/** 
 * @file src/debug-errori-warning.cpp
 * Tipi di errore e di warning.
 */

#include <iostream>

using namespace std;

class Quadrato
{
public:
    double operator()(double x) { return x * x; }
};

class C {
private:
    float _raggio;
    float _area;
public:
    C (int m) : _raggio(m) {}
    float getRaggio() { return _raggio; }
    float area() {
       Quadrato q;
       return 3.14159 * q(_raggio);
    }
};

int main(int argc, char** argv) 
{
    C c(10);
    
    cout << c.area() << endl;
    
    return 0;
}
