/** 
 * @file src/polimorfismo-operatori.cpp
 * Esempio di overload di un operatore.
 */

#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string s1 ("Pip");
    string s2 ("po");
    const char* s3 = "Plut";

    /** 
     *  La classe string definisce tre overload 
     *  per l'operatore += .
     *
     *  string& operator+= (const string& str);
     *  string& operator+= (const char* s);
     *  string& operator+= (char c);
     */
    s1 += s2;
    s1 += s3;

    cout << (s1 + 'o') << endl;

    return 0;
}
