/**
 * @file src/debug-error-handling.cpp
 * Ways of handling errors.
 */

#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

/** Error codes and strings */
#define LOG_DEBUG         1
#define LOG_WARNING       2
#define LOG_ERROR         3
#define ERR_NONE          0
#define ERR_FILE_NONE   -10
#define ERR_FILE_OPEN   -20
#define ERR_FILE_READ   -30
#define S_DEBUG         "DEBUG"
#define S_WARNING       "WARNING"
#define S_ERROR         "ERROR"
#define S_ERR_FILE_NONE "Please specify an input file"
#define S_ERR_FILE_OPEN "Unable to open the input file"
#define S_ERR_FILE_READ "Unable to read the input file"

/**
*   Defines a class derived from exception
*   for error handling.
*/
class Exception: public exception
{
private:
    int         _code;
    const char* _error;
public:

    /** Constructor */
    Exception(int code, const char* error)
    : _code(code), _error(error) {
    }

    /** Pure virtual function: must be redefined */
    virtual const char* what() const throw() {
        return _error;
    }

    /** Interface functions */
    int getCode() { return _code; }
    const char* getError() { return _error; }

    /** Redefinition of the output operator */
    friend ostream& operator<< (ostream& os, Exception e){
        os << e._code << ": " << e._error << endl;
        return os;
    }
};

/** Error-handling function */
void error(int code, bool exit = true)
{
    const char* error = NULL;

    /**
    *   Identifies the error string corresponding
    *   to the received error code.
    */
    switch(code) {
        case ERR_FILE_NONE: error = S_ERR_FILE_NONE; break;
        case ERR_FILE_OPEN: error = S_ERR_FILE_OPEN; break;
        case ERR_FILE_READ: error = S_ERR_FILE_READ; break;
    }

    /** If one is found, throws an exception */
    if(error != NULL){
        Exception e(code, error);
        throw e;
    }
}

/**
*   This is the log function we saw
*   in the lesson on functions.
*/
void log(int level, int n_params, ...)
{
    /** Defines the message level */
    const char* s_level;
    switch(level) {
        case LOG_DEBUG:   s_level = S_DEBUG  ; break;
        case LOG_WARNING: s_level = S_WARNING; break;
        default:          s_level = S_ERROR  ; break;
    }

    /** Writes the message text */
    cerr << '[' << s_level << "] ";

    /** Writes the parameters of the list */
    va_list param_list;
    va_start(param_list, n_params);
    for(int p = 1; p <= n_params; p++) {
        cerr << va_arg(param_list, char*) ;
    }
    va_end(param_list);

    cerr << endl;
}

/** Checks that the startup parameters are present */
int check_params(int argc, char** argv)
{
    return (argc < 2) ? ERR_FILE_NONE : ERR_NONE;
}

/** Opens the file for reading */
int open_file(ifstream& text, const char* path)
{
/**
*   This code is only compiled if
*   the __LOG__ macro is defined
*/
#ifdef __LOG__
    log(LOG_DEBUG, 2, "Opening file: ",  path);
#endif

    text.open(path);
    return ERR_NONE;
}

/** Reads the input file and writes it to the screen */
int process_file(ifstream& text)
{
    int  read = 0;
    char c = 0;
    while ((c = text.get()) != EOF) {
        read++;
        cout << c;
    }
    return read;
}

/** Closes the input file */
void close_file(ifstream& text)
{
    text.close();
}

int main(int argc, char** argv)
{
    ifstream text;

    try {

        int outcome = ERR_NONE;

        /**
        *   Checks that the input file name is present
        *   and handles any errors.
        */
        outcome = check_params(argc, argv);
        error(outcome);

        /**
        *   Sets the stream's exception mask so that
        *   an I/O error throws an exception,
        *   then opens the file for reading.
        *   Uses a try/catch block to intercept any
        *   exception and handle it in a way
        *   consistent with the rest of the code.
        *   It can't add a catch at the end, because
        *   the exception gives no information about the cause
        *   of the error that triggered it.
        */
        try {
            text.exceptions ( std::ifstream::badbit
                             | std::ifstream::failbit );
            outcome = open_file(text, argv[2]);
        } catch(ifstream::failure e) {
            error(ERR_FILE_OPEN);
        }

        /**
        *   Processes the text and handles any errors.
        *   Since the function returns the number of
        *   characters read, it must call error only
        *   if there are none.
        */
        text.exceptions ( std::ifstream::goodbit);
        if(process_file(text) == 0) {
            error(ERR_FILE_READ);
        }


        /** Closes the input file */
        close_file(text);

    } catch (Exception e) {
        cerr << e;
        exit(e.getCode());
    }

    return 0;
}
