/** 
 * @file src/stream-input-2.cpp
 * Programma di esempio per la gestione dell'input da stream.
 */
 
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{    
    char   buffer[256];
    string stringa;
    
    /** 
    *   Legge una stringa da tastiera tramite
    *   la funzione membro della classe istream.
    */
    cout << "Inserire una stringa: ";
    cin.getline(buffer, 256);
    cout << buffer << endl;


    /** 
    *   Legge una stringa da tastiera tramite
    *   la funzione globale getline.
    */
    cout << "Inserire una stringa: ";
    getline(cin, stringa);
    cout << stringa << endl;

    return 0;
}
