/**
 * @file functions-salary-error.cpp
 * Function that generates a compile error.
 */
#include <iostream>

/**
 * The main function calls the doubleSalary function,
 * but the compiler doesn't know it exists yet: error.
 */
int main(int argc, char** argv)
{
    std::cout << doubleSalary(1500) << std::endl;
    return 0;
}

/**
 * Definition of the doubleSalary function AFTER
 * its use by the main function.
 */
float doubleSalary(float salary)
{
    return salary * 2;
}
