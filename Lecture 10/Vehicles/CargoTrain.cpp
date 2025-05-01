#include "CargoTrain.h"

CargoTrain::CargoTrain()
{
    loadedDepotNumber = 0;
}

CargoTrain::CargoTrain(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int wagones, const char* name, unsigned int loadedDepotNumber) :Vehicle(year, weight, maxSpeed, wagones, name)
{
    this->loadedDepotNumber = loadedDepotNumber;
}

unsigned int CargoTrain::getLoadedDepotNumber() const
{
    return loadedDepotNumber;
}

void CargoTrain::readFrom(std::istream& is)
{
    Vehicle::readFrom(is);
    is >> loadedDepotNumber;
}
void CargoTrain::writeTo(std::ostream& os)const {
    Vehicle::writeTo(os);
    os << loadedDepotNumber;
}

 void CargoTrain::print()const
{
     Vehicle::print();
     std::cout <<""<< loadedDepotNumber;
}