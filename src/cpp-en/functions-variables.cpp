/**
 * @file functions-variables.cpp
 * Example of a function with variable parameters.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdarg>

#define LOG_DEBUG    1
#define LOG_WARNING  2
#define LOG_ERROR    3

#define S_DEBUG      "debug"
#define S_WARNING    "warning"
#define S_ERROR      "error"

#define ERR_NO_FILE_NAME  -1
#define ERR_NO_FILE_OPEN  -2

#define S_ERR_NO_FILE_NAME  "specify the file path"
#define S_ERR_NO_FILE_OPEN  "cannot open the file:"

using namespace std;

/** Output function with variable parameters */
void log(int level, int n_params, ...)
{

    /** Sets the width of the first field */
    cerr << setw(8);

    /** Writes the message level */
    switch(level) {
        case LOG_DEBUG:   cerr << S_DEBUG  ; break;
        case LOG_WARNING: cerr << S_WARNING; break;
        default:          cerr << S_ERROR  ; break;
    }

    /** Writes the separator character */
    cerr << " | ";

    /** Declares the variable for the parameter list */
    va_list param_list;

    /**
     * Initializes the parameter list and treats
     * every argument after n_params as variable.
     */
    va_start(param_list, n_params);

    /** Reads all the parameters in the list and prints them on screen */
    for(int p = 1; p <= n_params; p++) {
        cerr << va_arg(param_list, char*) ;
    }

    /** Closes the parameter list */
    va_end(param_list);

    /** Writes the message text */
    cerr << endl;

}

int main(int argc, char** argv)
{
    /** Creates a variable to handle the output file */
    ofstream doc;

    /** Pointer for the output file name */
    const char* filename = NULL;

    /** If the output file name is missing, error */
    if(argc < 2) {
        log(LOG_ERROR, 1, S_ERR_NO_FILE_NAME);
        return ERR_NO_FILE_NAME;
    }

    /** Reads the output file name */
    filename = argv[1];

    /** Tries to open the output file */
    doc.open (argv[1]);

    /** If there was an error, reports it and exits */
    if(!doc.is_open()) {
        log(LOG_ERROR, 2, S_ERR_NO_FILE_OPEN, filename);
        return ERR_NO_FILE_OPEN;
    }

    /** OK, the file is ready */
    log(LOG_WARNING, 2, "opened the file: ", filename);

    /** Writes to the output file */
    doc << "Document text.\n";
    log(LOG_DEBUG, 2, "wrote to the file: ", filename);

    /** Closes the output file */
    doc.close();
    log(LOG_WARNING, 2,  "closed the file: ", filename);

    return 0;
}
