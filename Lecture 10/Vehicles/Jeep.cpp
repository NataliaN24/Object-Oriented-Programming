#include "Jeep.h"

Jeep::Jeep()
{
    is4x4 = false;
}

Jeep::Jeep(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int tires, const char* name, bool is4x4):Vehicle(year,weight,maxSpeed,tires,name)
{
    this->is4x4 = is4x4;
}

bool Jeep::getIs4X4() const
{
    return is4x4;
}

void Jeep::readFrom(std::istream& is) 
{
    Vehicle::readFrom(is);
    is >> is4x4;

}
void Jeep::writeTo(std::ostream& os)const {
    Vehicle::writeTo(os);
    os << is4x4;
 }

void Jeep::print()const
{
    Vehicle::print();
    std::cout << "" << is4x4;
}