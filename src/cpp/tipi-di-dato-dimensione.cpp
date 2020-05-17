#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{    
    int w = 12;
    
    /** Mostra la dimensione dei tipi di dato */
    cout << setw(w) << "bool: "   << sizeof(bool)   << endl;
    cout << setw(w) << "char: "   << sizeof(char)   << endl;
    cout << setw(w) << "int: "    << sizeof(int)    << endl;
    cout << setw(w) << "float: "  << sizeof(float)  << endl;
    cout << setw(w) << "double: " << sizeof(double) << endl;
    
    return 0;
}
