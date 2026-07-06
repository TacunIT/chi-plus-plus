/**
 * @file functions-inline-3.cpp
 * Example of an inline function.
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#define LOG_DEBUG    1
#define LOG_WARNING  2
#define LOG_ERROR    3

#define S_DEBUG      "debug"
#define S_WARNING    "warning"
#define S_ERROR      "error"

#define ERR_NO_FILE_NAME  -1
#define ERR_NO_FILE_OPEN  -2

using namespace std;

/** Inline output function */
inline void log(const char* message, int level)
{
    /** Sets the width of the first field */
    cerr << setw(8);

    /** Writes the message level */
    switch(level) {
        case LOG_DEBUG:   cerr << S_DEBUG  ; break;
        case LOG_WARNING: cerr << S_WARNING; break;
        default:          cerr << S_ERROR  ; break;
    }

    /** Writes the message text */
    cerr << ": " << message << endl;
}

int main(int argc, char** argv)
{
    /** Creates a variable to handle the output file */
    ofstream doc;

    /** Pointer for the output file name */
    const char* filename = NULL;

    /** If the output file name is missing, error */
    if(argc < 2) {
        log("specify the file path", LOG_ERROR);
        return ERR_NO_FILE_NAME;
    }

    /** Reads the output file name */
    filename = argv[1];

    /** Tries to open the output file */
    doc.open (argv[1]);

    /** If there was an error, reports it and exits */
    if(!doc.is_open()) {
        log("cannot open the file", LOG_ERROR);
        return ERR_NO_FILE_OPEN;
    }

    /** OK, the file is ready */
    log("opened the file", LOG_WARNING);

    /** Writes to the output file */
    doc << "Document text.\n";
    log("wrote to the file", LOG_DEBUG);

    /** Closes the output file */
    doc.close();
    log("closed the file", LOG_WARNING);

    return 0;
}
