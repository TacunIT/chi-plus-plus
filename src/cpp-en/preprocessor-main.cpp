/**
 * @file src/preprocessor-main.cpp
 * Shows the possible values for C++'s main data types.
 */

#include <iostream>
#include <iomanip>

#define LANG_IT
#include "preprocessor-color.h"
#undef LANG_IT

#ifdef LANG_IT
    #define  STR_BOOL   "booleano"
    #define  STR_CHAR   "carattere"
    #define  STR_INT    "intero"
    #define  STR_DEC    "decimale"
    #define  STR_ARRAY  "array"
    #define  STR_VERDE  "verde"
#else
    #define  STR_BOOL   "boolean"
    #define  STR_CHAR   "character"
    #define  STR_INT    "integer"
    #define  STR_DEC    "decimal"
    #define  STR_ARRAY  "array"
    #define  STR_VERDE  "green"
#endif

using namespace std;

int main()
{
    /** Declares a series of variables */
    bool    boolean = false;
    char    character = 'C';
    int     integer = 1234567890;
    float   decimal = 3.14;
    char    array[] = "abcdefghilmnopqrstuvz";
    RGB     enumValue = green;

    /** Creates an object of type Color */
    Color   color;

    /**
     * Assigns a value to the data of the rgbColor struct
     * inside the object of type Color.
     */
    color.rgbColor.value = enumValue;
    color.rgbColor.name = STR_VERDE;

    /** Displays the value of the variables */
    cout << setw(10) << STR_BOOL  << ": " << boolean   << endl;
    cout << setw(10) << STR_CHAR  << ": " << character << endl;
    cout << setw(10) << STR_INT   << ": " << integer   << endl;
    cout << setw(10) << STR_DEC   << ": " << decimal   << endl;
    cout << setw(10) << STR_ARRAY << ": " << array     << endl;

    /** Displays the color's name */
    color.color_name();

    return 0;
}
