/** 
 * @file _man/src/operatori-pre-post.cpp
 * Utilizzo degli operatori di incremento e decremento.
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{   
    /** Definizione delle due variabili */
    int pre  = 5, post = 7; 

    /** Operatore di incremento, prima e dopo la variabile */
    cout << "pre-incremento: " << ++pre  << endl;
    cout << "post-incremento:" << post++ << endl;

    /** Operatore di decremento, prima e dopo la variabile */
    cout << "pre-decremento: " << --pre  << endl;
    cout << "post-decremento:" << post-- << endl;

    return 0;
}
