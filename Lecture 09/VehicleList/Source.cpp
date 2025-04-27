#include <iostream>
#include "VehicleList.h"

int main()
{
    try
    {
        // Създаваме празен списък с капацитет 5
        VehicleList list(5);

        std::cout << "Immediately after creation:" << std::endl;
        std::cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Size: " << list.getSize() << std::endl;
        std::cout << "Capacity: " << list.getCapacity() << std::endl;

        // Създаваме превозно средство
        Registration reg("CA1234AB");
        Vehicle v1(reg, "Red BMW");

        // Добавяме го в списъка
        list.addVehicle(v1);

        std::cout << "\nAfter adding one vehicle:" << std::endl;
        std::cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Size: " << list.getSize() << std::endl;
        std::cout << "Capacity: " << list.getCapacity() << std::endl;

        // Показваме какво има на позиция 0
        std::cout << "\nVehicle at index 0:" << std::endl;
        std::cout << list[0].getRegistration().getRegNumber() << " - " << list[0].getDescription() << std::endl;

        // Търсим регистрационен номер
        Registration searchReg("CA1234AB");
        Vehicle* found = list.getByRegNumber(searchReg);

        if (found)
        {
            std::cout << "\nFound vehicle: " << found->getDescription() << std::endl;
        }
        else
        {
            std::cout << "\nVehicle not found!" << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
