/** 
 * @file classi-classe-orario-1.cpp
 * Gestione dei dati membro di una classe.
 */
 
#include <iostream>
#include <iomanip> 

using namespace std;

/** Dichiarazione della classe */
class Orario {
private:
    int _h;
    int _m;
    int _s;
public:
    Orario(int h = 0, int m = 0, int s = 0);
};

/** Definizione del costruttore della classe */
Orario::Orario(int h, int m, int s) 
: _h(h), _m(m), _s(s) 
{
}
    
/** La funzione main non fa parte della classe */
int main()
{    
    Orario ora;

    /** Questo codice darà errore */
    cout << setfill('0') << setw(2) << ora._h << ":" 
         << setfill('0') << setw(2) << ora._m << ":" 
         << setfill('0') << setw(2) << ora._s << endl;
    
    return 0;
}
