/**
 * @file src/debug-errors-warnings.cpp
 * Types of errors and warnings.
 */

#include <iostream>

using namespace std;

class Square
{
public:
    double operator()(double x) { return x * x; }
};

class Circle {
private:
    float _radius;
    float _area;
public:
    Circle (int m) : _radius(m) {}
    float getRadius() { return _radius; }
    float area() {
       Square s;
       return 3.14159 * s(_radius);
    }
};

int main(int argc, char** argv)
{
    Circle c(10);
    cout << c.area() << endl;
    return 0;
}
