#include "PrimeIterator.h"
#include <iostream>

int main()
{
    for (PrimeIterator it(2); *it < 100; it++) {
        std::cout << *it << " ";
    }
}
