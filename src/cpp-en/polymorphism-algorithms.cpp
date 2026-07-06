/**
 * @file src/polymorphism-algorithms.cpp
 * Example use of STL algorithms.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /** Creates the vector */
    vector<int> vect;

    /** Adds values to the vector */
    vect.push_back(10);
    vect.push_back(70);
    vect.push_back(21);
    vect.push_back(49);
    vect.push_back(35);

    /** Shows the highest and lowest values */
    cout << *min_element(vect.begin(), vect.end()) << endl;
    cout << *max_element(vect.begin(), vect.end()) << endl;

    /** Shows the values in the order they were inserted */
    vector<int>::iterator i;
    for(i = vect.begin(); i != vect.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    /** Sorts the values from lowest to highest and displays them */
    int n = vect.size();
    sort(vect.begin(), vect.end());
    for (int i=0; i<n; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;

    /** Sorts the values from highest to lowest and displays them */
    reverse(vect.begin(), vect.end());
    for (int i=0; i<n; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;


    return 0;
}
