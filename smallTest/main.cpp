#include <iostream>
#include "test_variable_life.h"
#include "test_variable_life2.h"

int main()
{
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;

   // func2();

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    const int *a = new int(5);
    a = new int(6);
    *a = 6;
}