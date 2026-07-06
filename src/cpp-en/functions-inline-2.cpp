/**
 * @file functions-inline-2.cpp
 * Example of code with a single output function.
 */

#include <iostream>
#include <fstream>

#define S_FILENAME  "src/out/example.txt"

using namespace std;

/** Single output function */
void log(const char* message)
{
    /** Displays the message on screen */
    cout << message << endl;
}

int main(int argc, char** argv)
{
    /** Creates a variable to handle the output file */
    ofstream doc;

    /** Opens the output file */
    doc.open (S_FILENAME);
    log("opened the file");

    /** Writes to the output file */
    doc << "Document text.\n";
    log("wrote to the file");

    /** Closes the output file */
    doc.close();
    log("closed the file");

    return 0;
}
