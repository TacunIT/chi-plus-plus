/**
 * @file debug-stochastic-error.cpp
 * Error that only occurs under certain circumstances.
 */

#include <iostream>
#include <fstream>

using namespace std;

#define ERR_FILE_NONE       -10
#define ERR_FILE_OPEN       -20
#define S_ERR_FILE_NONE     "Please specify an input file"
#define S_ERR_FILE_OPEN     "Unable to open the input file"
#define N_CHAR_MIN          300
#define N_BANNER_MAX        3
#define DOT                 '.'

/**
*   Adds a banner after every dot,
*   every N_CHAR_MIN characters.
*/
int banner_text(ifstream& text)
{
    int  n_banner = 1;
    int  read = 0;
    char c = 0;

    /**
    *  Reads the entire content of the input file
    */
    while(text.good()) {

        /**
        *   Reads the content of the file,
        *   character by character
        */
        if((c = text.get()) != EOF) {

            /** Increments the number of characters read */
            read++;

            /** Writes the character read */
            cout << c;

            /**
            *   If the current character is a dot
            *   and it has read at least N_CHAR_MIN characters
            *   and there are still banners left to add,
            *   inserts the banner code into the text.
            */
            if(c == DOT
            && read >= N_CHAR_MIN
            && n_banner <= N_BANNER_MAX) {
                cout << endl
                     << "<div id=\"banner-"
                     << n_banner
                     << "\"></div>"
                     << endl;
                n_banner++;
                read = 0;
            }
        }
    }

    cout << endl;

    return n_banner;
}

int main(int argc, char** argv)
{
    ifstream text;

    /** Checks that the input file name is present */
    if(argc < 2) {
        cerr << S_ERR_FILE_NONE << endl;
        exit(ERR_FILE_NONE);
    }

    /** Opens the file for reading */
    text.open(argv[1]);
    if(!text.good()) {
        cerr << S_ERR_FILE_OPEN << endl;
        exit(ERR_FILE_OPEN);
    }

    /** Processes the text */
    banner_text(text);

    /** Closes the file */
    text.close();

    return 0;
}
