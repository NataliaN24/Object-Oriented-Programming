#include <iostream>
#include "Registration.h"

int main()
{
    try
    {
        Registration r1("CA1234AB"); // валиден
        Registration r2("C1234AB");  // валиден
        Registration r3("1234AB");   // невалиден

        std::cout << "First: " << r1.getRegNumber() << std::endl;
        std::cout << "Second: " << r2.getRegNumber() << std::endl;

        if (r1 == r2)
            std::cout << "Same registration" << std::endl;
        else
            std::cout << "Different registrations" << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
}
