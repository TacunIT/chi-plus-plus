#include <iostream>
#include <cstdlib>

#define POS_NESSUNO -1
#define POS_ERRORE   0
#define POS_MERCURIO 1
#define POS_VENERE   2
#define POS_TERRA    3
#define POS_MARTE    4
#define POS_GIOVE    5
#define POS_SATURNO  6
#define POS_URANO    7
#define POS_NETTUNO  8
#define POS_PLUTONE  9

using namespace std;

int main(int argc, char** argv)
{    
    int pianeta;
    
    if(argc > 1) {
        pianeta = atoi(argv[1]);
    } else {
        pianeta = POS_NESSUNO;
    }
    
    switch( pianeta ) {
        case 0: 
            cout << "Il valore inserito non è valido";
            break;
        case POS_MERCURIO: 
            cout << "Mercurio";
            break;
        case POS_VENERE: 
            cout << "Venere";
            break;
        case POS_TERRA: 
            cout << "Terra";
            break;
        case POS_MARTE: 
            cout << "Marte";
            break;
        case POS_GIOVE: 
            cout << "Giove";
            break;
        case POS_SATURNO: 
            cout << "Saturno";
            break;
        case POS_URANO: 
            cout << "Urano";
            break;
        case POS_NETTUNO: 
            cout << "Nettuno";
            break;
        case POS_PLUTONE:
            cout << "Plutone";
            break;
        default:
            cout << "Inserire un valore da: " 
                 << POS_MERCURIO 
                 << " a " 
                 << POS_PLUTONE;                    
    }
    
    cout << endl;
    
    return 0;
}
