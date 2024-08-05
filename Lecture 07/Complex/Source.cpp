#include <iostream>
#include "Complex.h"

int main() {
    Complex z1(3, 2);
    Complex z2(1, 4);

    Complex sum = z1 + z2;
    Complex difference = z1 - z2;
    Complex product = z1 * z2;
    Complex quotient = z1 / z2;

    std::cout << "z1: " << z1 << std::endl;
    std::cout << "z2: " << z2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}