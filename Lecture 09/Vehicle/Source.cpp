#include <iostream>
#include "Vehicle.h"

int main()
{
    try
    {
        // Създаваме регистрация
        Registration reg("CA1234AB");

        // Създаваме превозно средство с регистрация и описание
        Vehicle vehicle(reg, "Red BMW 320d");

        // Принтираме информацията
        std::cout << "Registration: " << vehicle.getRegistration().getRegNumber() << std::endl;
        std::cout << "Description: " << vehicle.getDescription() << std::endl;

        // Правим копие на превозното средство
        Vehicle vehicleCopy = vehicle;

        std::cout << "\nCopied Vehicle:" << std::endl;
        std::cout << "Registration: " << vehicleCopy.getRegistration().getRegNumber() << std::endl;
        std::cout << "Description: " << vehicleCopy.getDescription() << std::endl;

        // Тест на оператор=
        Registration reg2("CB9876XX");
        Vehicle anotherVehicle(reg2, "Blue Mercedes C-Class");

        std::cout << "\nBefore assignment:" << std::endl;
        std::cout << "Registration: " << anotherVehicle.getRegistration().getRegNumber() << std::endl;
        std::cout << "Description: " << anotherVehicle.getDescription() << std::endl;

        anotherVehicle = vehicle;

        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << "Registration: " << anotherVehicle.getRegistration().getRegNumber() << std::endl;
        std::cout << "Description: " << anotherVehicle.getDescription() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
