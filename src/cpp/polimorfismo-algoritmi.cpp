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
    /** Crea il vettore */
    vector<int> vect;

    /** Aggiunge dei valori al vettore */
    vect.push_back(10);
    vect.push_back(70);
    vect.push_back(21);
    vect.push_back(49);
    vect.push_back(35);

    /** Mostra il valore più alto e il più basso */
    cout << *min_element(vect.begin(), vect.end()) << endl;
    cout << *max_element(vect.begin(), vect.end()) << endl;
    
    /** Mostra i valori nell'ordine in cui sono stati inseriti */
    vector<int>::iterator i;
    for(i = vect.begin(); i != vect.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    /** Ordina i valori dal più basso al più alto e li visualizza */
    int n = vect.size();
    sort(vect.begin(), vect.end());
    for (int i=0; i<n; i++) {
        cout << vect[i] << " ";       
    }
    cout << endl;

    /** Ordina i valori dal più alto al più basso e li visualizza */
    reverse(vect.begin(), vect.end());
    for (int i=0; i<n; i++) {
        cout << vect[i] << " ";       
    }
    cout << endl;

 
    return 0;
}
