#include "PassengerTrain.h"

PassengerTrain::PassengerTrain()
{
    passengerNumber = 0;
}

PassengerTrain::PassengerTrain(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int wagones, const char* name, unsigned int passNumber) :Vehicle(year, weight, maxSpeed, wagones, name)
{
    passengerNumber = passNumber;
}

unsigned int PassengerTrain::getPassengerNumber() const
{
    return passengerNumber;
}


void PassengerTrain::readFrom(std::istream& is)
{
    Vehicle::readFrom(is);
    is >> passengerNumber;

}
void PassengerTrain::writeTo(std::ostream& os)const {
    Vehicle::writeTo(os);
    os << passengerNumber;
}

void PassengerTrain::print()const
{
    Vehicle::print();
    std::cout << "" << passengerNumber;
}