/**
 * @file src/data-types-pointers.cpp
 * Handling pointers and binary data.
 */

#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

/**
 * Defines two data types: one byte long
 * and one two bytes long
 */
typedef unsigned char byte;
typedef short int twobyte;

int main()
{
    /** Creates an array of 80 binary values */
    byte values[] = {
          0b01000011, 0b00100111, 0b01101000, 0b01100001
        , 0b01101110, 0b01101110, 0b01101111, 0b00100000
        , 0b01100110, 0b01101111, 0b01110010, 0b01110011
        , 0b01100101, 0b00100000, 0b01110100, 0b01110101
        , 0b01110100, 0b01110100, 0b01100101, 0b00100000
        , 0b01100101, 0b00100000, 0b01100100, 0b01110101
        , 0b01100101, 0b00100000, 0b01101100, 0b01100001
        , 0b00100000, 0b01110011, 0b01110100, 0b01100101
        , 0b01110011, 0b01110011, 0b01100001, 0b00100000
        , 0b01100101, 0b01110100, 0b11100000, 0b00100000
        , 0b00001010, 0b01001010, 0b01100101, 0b00100000
        , 0b01100110, 0b01101001, 0b01101111, 0b01110010
        , 0b01101001, 0b01110011, 0b01100011, 0b01100101
        , 0b00100000, 0b01100100, 0b01100101, 0b01101110
        , 0b01110100, 0b01110010, 0b01101111, 0b00100000
        , 0b01100001, 0b01110010, 0b00100000, 0b01100011
        , 0b01101111, 0b01110010, 0b01100101, 0b00100000
        , 0b00100111, 0b01101110, 0b00100000, 0b01101001
        , 0b01101100, 0b01101100, 0b01110101, 0b01110011
        , 0b01101001, 0b01101111, 0b01101110, 0b01100101
    };
    /**
     * Creates a pointer with a size of eight bits and
     * assigns it the address of the start of the array.
     */
    byte * p1 = values;

    /**
     * Moves the pointer across the whole length of the array,
     * showing for each byte its binary value, its
     * value converted to decimal, and the letter of the
     * ASCII set corresponding to that value.
     */
    for(int i = 0; i < sizeof(values); i++) {
        cout << setw(4)  << i
             << setw(18) << bitset<8>(*p1)
             << setw(6)  << (int)*p1
             << setw(4)  << (char) *p1 << endl;

        /** Moves the pointer to the next byte. */
        p1++;
    }

    cout << endl;

    /**
     * Creates a new pointer, this time with a
     * size of sixteen bits.
     */
    twobyte * p2 = (twobyte*)values;

    /**
     * Reads the array's values again,
     */
    for(int i = 0; i < sizeof(values) / 2; i++) {
        cout << setw(4)  << i
             << setw(18) << bitset<16>(*p2)
             << setw(6)  << (short)*p2
             << setw(4)  << (char) *p2 << endl;

        /** Moves the pointer by two bytes. */
        p2++;
    }
    return 0;
}
