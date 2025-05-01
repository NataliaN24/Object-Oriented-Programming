#include <iostream>
#include "Jeep.h"
#include "Van.h"
#include "PassengerTrain.h"
#include "CargoTrain.h"

int main() {
    Jeep jeep(2020, 2000, 180, 4, "JEEP-RM-001", true);
    Van van(2019, 3500, 150, 6, "VAN-RM-002", 5000);
    PassengerTrain pTrain(2010, 70000, 120, 10, "Georgi Ivanov", 400);
    CargoTrain cTrain(2015, 95000, 100, 8, "Petar Petrov", 12);

    jeep.print();
    van.print();
    pTrain.print();
    cTrain.print();

    Jeep jeep2;
    jeep2.readFrom(std::cin);
    jeep2.print();

    Van van2;
    van2.readFrom(std::cin);
    van2.print();

    PassengerTrain pTrain2;
    pTrain2.readFrom(std::cin);
    pTrain2.print();

    CargoTrain cTrain2;
    cTrain2.readFrom(std::cin);
    cTrain2.print();

    return 0;
}
