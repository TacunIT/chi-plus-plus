/** 
 * @file src/polimorfismo-algoritmi.cpp
 * Esempio di utilizzo degli algoritmi della STL.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vect;
    
    vect.push_back(10);
    vect.push_back(70);
    vect.push_back(21);
    vect.push_back(49);
    vect.push_back(35);

    cout << *min_element(vect.begin(), vect.end()) << endl;
    cout << *max_element(vect.begin(), vect.end()) << endl;
    
    vector<int>::iterator i;
    for(i = vect.begin(); i != vect.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    int n = vect.size();
    sort(vect.begin(), vect.end());
    for (int i=0; i<n; i++) {
        cout << vect[i] << " ";       
    }
    cout << endl;

    reverse(vect.begin(), vect.end());
    for (int i=0; i<n; i++) {
        cout << vect[i] << " ";       
    }
    cout << endl;

 
    return 0;
}
