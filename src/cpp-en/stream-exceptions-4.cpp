/**
 * @file src/stream-exceptions-4.cpp
 * Example program for handling exceptions.
 * Requires, as input, the number of characters to read
 * and the path of the input file:
 *
 *    src/out/example <n characters to read> <input file>
 */

#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

/** Error codes and strings */
#define ERR_NONE          0
#define ERR_PARAMETERS  -10
#define ERR_FILE_OPEN   -20
#define S_SYNTAX        "USAGE: example <n characters> <file path>"
#define S_ERR_PARAMETERS "Error in the input parameters."
#define S_ERR_FILE_OPEN "Unable to open the input file"

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

int main(int argc, char** argv)
{
    ifstream text;
    text.exceptions ( ios_base::badbit );

    try {

        char c     = 0;
        int  read  = 0;

        /**
        *   Checks that both the input file name
        *   and the number of characters to read are present.
        */
        if (argc < 3)
            throw Exception(ERR_PARAMETERS, S_ERR_PARAMETERS);

        /** Defines the number of characters to read */
        int to_read = atoi(argv[1]);

        /**
        *   Sets the stream's exception mask so that
        *   an I/O error throws an exception,
        *   then opens the file for reading.
        *   Uses a try/catch block to intercept any
        *   exception and handle it in a way
        *   consistent with the rest of the code.
        */
        try {
            text.exceptions ( ios_base::badbit
                             | ios_base::failbit );
            text.open(argv[2]);
        } catch(ifstream::failure e) {
            throw Exception(ERR_FILE_OPEN, S_ERR_FILE_OPEN);
        }

        /**
        *   Resets the exception mask to avoid
        *   exceptions at end of file.
        */
        text.exceptions ( ios_base::goodbit);

        /**
        *   Reads the text and prints it to the screen.
        *   If a maximum number of characters was defined,
        *   it stops there.
        */
        while(text.good()) {
            if((c = text.get()) != EOF) {
                read++;
                cout << c;
            }
            if((to_read != 0) && (read >= to_read)) {
                cout << endl;
                break;
            }
        }

        /** Closes the input file */
        text.close();

    } catch (Exception e) {

        /** Prints the exception to the screen */
        cerr << e << endl;

        /** Shows the calling syntax **/
        cerr << S_SYNTAX << endl;

        /** Exits with an error code */
        exit(e.getCode());
    }

    return 0;
}
