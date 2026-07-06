/**
 * @file functions-salary-main.cpp
 * Main function of the program with separate object files.
 */
#include <iostream>

/**
 * Declaration of the doubleSalary function.
 * I put it here for simplicity: usually, declarations
 * live in a separate include file.
 */
float doubleSalary(float salary);

/**
 * The main function calls the doubleSalary function,
 * which is defined in another source file.
 */
int main(int argc, char** argv)
{
    std::cout << doubleSalary(1500) << std::endl;
    return 0;
}
