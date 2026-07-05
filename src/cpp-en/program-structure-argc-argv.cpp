#include <iostream>

#define NO_ERRORS     0
#define NO_PARAMETERS 1

int main(int argc, char** argv)
{
    int error = NO_ERRORS;

    /** If there's only the program's name, error */
    if(argc < 2) {
        std::cerr << "Specify a parameter!" << std::endl;
        return NO_PARAMETERS;
    }

    /** Print all the parameters received */
    for(int p=0; p < argc; p++) {
        std::cout << *argv++ << std::endl;
    }

    return 0;
}
