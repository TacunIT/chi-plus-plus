#include <iostream>
#include <iomanip> 
#include <limits>

using namespace std;

int main()
{    
    int w = 12;
    
    /** Mostra i valori minimi e massimi per tipi di dato */
    cout << setw(w) << "tipo"
         << setw(w) << "minimo"   
         << setw(w) << "massimo"
         << endl;      
    cout << setw(w) << "bool: "   
         << setw(w) << numeric_limits<bool>::min()
         << setw(w) << numeric_limits<bool>::max() 
         << endl;
    cout << setw(w) << "char: "   
         << setw(w) << (unsigned int) numeric_limits<unsigned char>::min()
         << setw(w) << (unsigned int) numeric_limits<unsigned char>::max() 
         << endl;
    cout << setw(w) << "int: "   
         << setw(w) << numeric_limits<unsigned int>::min()
         << setw(w) << numeric_limits<unsigned int>::max() 
         << endl;
    cout << setw(w) << "float: "   
         << setw(w) << numeric_limits<float>::min()
         << setw(w) << numeric_limits<float>::max() 
         << endl;
    cout << setw(w) << "double: "   
         << setw(w) << numeric_limits<double>::min()
         << setw(w) << numeric_limits<double>::max() 
         << endl;
    return 0;
}
