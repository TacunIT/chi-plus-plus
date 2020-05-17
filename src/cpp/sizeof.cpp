#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;
int main()
{
int w = 20;
cout << setw(w) << "TIPO"
<< setw(w) << "BYTES"
<< setw(w) << "MIN"
<< setw(w) << "MAX" << endl;
cout << setw(w) << "int"
<< setw(w) << sizeof(int)
<< setw(w) << numeric_limits<int>::min()
<< setw(w) << numeric_limits<int>::max() << endl;
cout << setw(w) << "char"
<< setw(w) << sizeof(char)
<< setw(w) << (int) numeric_limits<char>::min()
<< setw(w) << (int) numeric_limits<char>::max() << endl;
cout << setw(w) << "float"
<< setw(w) << sizeof(float)
<< setw(w) << numeric_limits<float>::min()
<< setw(w) << numeric_limits<float>::max() << endl;
cout << setw(w) << "double"
<< setw(w) << sizeof(double)
<< setw(w) << numeric_limits<double>::min()
<< setw(w) << numeric_limits<double>::max() << endl;
cout << setw(w) << "bool"
<< setw(w) << sizeof(bool)
<< setw(w) << numeric_limits<bool>::min()
<< setw(w) << numeric_limits<bool>::max() << endl;
/* Attenzione: queste righe generano errori di compilazione!
cout << setw(w) << "void"
<< setw(w) << sizeof(void)
<< setw(w) << numeric_limits<void>::min()
<< setw(w) << numeric_limits<void>::max() << endl;
*/
return 0;
}
