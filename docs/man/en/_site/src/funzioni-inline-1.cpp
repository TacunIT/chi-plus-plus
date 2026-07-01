/** 
 * @file funzioni-inline-1.cpp
 * Esempio di codice con istruzioni ripetute.
 */

#include <iostream>
#include <iomanip> 
#include <fstream>

#define S_FILENAME  "src/out/esempio.txt"

using namespace std;

int main(int argc, char** argv)
{        
    /** 
     * Crea una variabile di classe ofstraeam 
     * per gestire il file di output  */
    ofstream doc;

    /** Apre il file di output */
    doc.open (S_FILENAME);
    cout << "ho aperto il file " << endl;

    /** Scrive sul file di output */
    doc << "Testo del documento.\n";
    cout << "ho scritto sul file" << endl;

    /** Chiude il file di output */
    doc.close();
    cout << "ho chiuso il file" << endl;

    return 0;
}
