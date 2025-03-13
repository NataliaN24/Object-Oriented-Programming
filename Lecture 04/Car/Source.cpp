#include "Car.h"
#include <iostream>
#include <fstream>

int main()
{
    const char* carName = "Toyota";
    unsigned int kmArr[] = { 100, 200, 150, 300 };
    size_t kmCount = sizeof(kmArr) / sizeof(kmArr[0]);

    Car myCar(2022, 220, carName, kmArr, kmCount);

    // Write to file
    std::ofstream ofs("car_data.bin", std::ios::binary);
    if (ofs.is_open())
    {
        myCar.writeToFile(ofs);
        ofs.close();
    }
    else
    {
        std::cerr << "Error opening file for writing!\n";
        return 1;
    }

    // Read from file
    Car loadedCar;
    std::ifstream ifs("car_data.bin", std::ios::binary);
    if (ifs.is_open())
    {
        loadedCar.readFromFile(ifs);
        ifs.close();
    }
    else
    {
        std::cerr << "Error opening file for reading!\n";
        return 1;
    }

    // Display results
    std::cout << "Total KM driven: " << myCar.howManyKm() << std::endl;
    std::cout << "Longest single ride: " << myCar.theLongestRide() << " km" << std::endl;

    return 0;
}
