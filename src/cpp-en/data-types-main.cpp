#include <iostream>

using namespace std;

/** Defines an enumerated data type named RGB */
enum RGB { red = 0xFF0000, green = 0x00ff00, blue = 0x0000ff };
/** Defines a struct that holds an RGB color and a name */
struct RGBColor {
    RGB  value;
    const char* name;
};

/**
 * Defines the Color class, which holds an rgbColor
 * and a function that displays its name.
 */
class Color {
public:
    RGBColor rgbColor;
    void color_name() {
        cout << "colorRGB:";
        switch(rgbColor.value) {
            case red  : cout << "red"  ; break;
            case green: cout << "green"; break;
            case blue : cout << "blue" ; break;
        }
        cout << endl;
    }
};

int main()
{
    /** Declares a series of variables */
    bool    boolean   = false;
    char    character = 'C';
    int     integer   = 1234567890;
    float   decimal   = 3.14;
    char    array[]   = "abcdefghilmnopqrstuvz";
    RGB     enumValue = green;

    /** Creates an object of type Color */
    Color   color;

    /**
     * Assigns a value to the data of the rgbColor struct
     * inside the object of type Color.
     */
    color.rgbColor.value = enumValue;
    color.rgbColor.name = "green";
    /** Displays the value of the variables */
    cout << "boolean:"   << boolean   << endl;
    cout << "character:" << character << endl;
    cout << "integer:"   << integer   << endl;
    cout << "decimal:"   << decimal   << endl;
    cout << "array:"     << array     << endl;

    /** Displays the color's name */
    color.color_name();

    return 0;
}
