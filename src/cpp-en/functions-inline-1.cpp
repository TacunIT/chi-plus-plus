/**
 * @file functions-inline-1.cpp
 * Example of code with repeated instructions.
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#define S_FILENAME  "src/out/example.txt"

using namespace std;

int main(int argc, char** argv)
{
    /**
     * Creates a variable of the ofstream class
     * to handle the output file  */
    ofstream doc;

    /** Opens the output file */
    doc.open (S_FILENAME);
    cout << "opened the file " << endl;

    /** Writes to the output file */
    doc << "Document text.\n";
    cout << "wrote to the file" << endl;

    /** Closes the output file */
    doc.close();
    cout << "closed the file" << endl;

    return 0;
}
