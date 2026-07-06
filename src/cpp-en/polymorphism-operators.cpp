/**
 * @file src/polymorphism-operators.cpp
 * Example of operator overloading.
 */

#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string s1 ("Foo");
    string s2 ("ba");
    const char* s3 = "r";

    /**
     *  The string class defines three overloads
     *  for the += operator.
     *
     *  string& operator+= (const string& str);
     *  string& operator+= (const char* s);
     *  string& operator+= (char c);
     */
    s1 += s2;
    s1 += s3;

    cout << (s1 + '!') << endl;

    return 0;
}
