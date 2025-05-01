#include "Van.h"

Van::Van()
{
	loadCapacity = 0;
}

Van::Van(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int tires, const char* name, unsigned int loadCap):Vehicle(year, weight, maxSpeed, tires, name)
{
	this->loadCapacity = loadCap;
}

unsigned int Van::getCapacity() const
{
	return loadCapacity;
}

void Van::readFrom(std::istream& is)
{
    Vehicle::readFrom(is);
    is >> loadCapacity;

}
void Van::writeTo(std::ostream& os)const {
    Vehicle::writeTo(os);
    os << loadCapacity;
}

void Van::print()const
{
    Vehicle::print();
    std::cout << "" << loadCapacity;
}