#ifndef _CLASS_COLOR
#define _CLASS_COLOR 1

#define  RGB_RED    0xFF0000
#define  RGB_GREEN  0x00FF00
#define  RGB_BLUE   0x0000FF

#ifdef LANG_IT
    #define  STR_RGB    "colore RGB"
    #define  STR_RED    "rosso"
    #define  STR_GREEN  "verde"
    #define  STR_BLUE   "blu"
#else
    #define  STR_RGB    "RGB color"
    #define  STR_RED    "red"
    #define  STR_GREEN  "green"
    #define  STR_BLUE   "blue"
#endif

#include <iostream>

using namespace std;

/** Defines an enumerated data type named RGB */
enum RGB { red = RGB_RED, green = RGB_GREEN, blue = RGB_BLUE };

/** Defines a struct that holds an RGB color and a name */
struct RGBColor {
    RGB  value;
    const char* name;
};

/**
 * Defines the Color class, which holds an
 * rgbColor struct and a function that displays its name.
 */
class Color {
public:
    RGBColor rgbColor;
    void color_name() {
        cout << STR_RGB << ": ";
        switch(rgbColor.value) {
            case red  : cout << STR_RED  ; break;
            case green: cout << STR_GREEN; break;
            case blue : cout << STR_BLUE ; break;
        }
        cout << endl;
    }
};

#endif /* _CLASS_COLOR */
