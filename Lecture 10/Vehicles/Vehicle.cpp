#include "Vehicle.h"

void Vehicle::copyFrom(const Vehicle& other)
{
    yearOfCreation = other.yearOfCreation;
    weight = other.weight;
    maxSpeed = other.maxSpeed;
    NumberOfTiresOrWagons = other.NumberOfTiresOrWagons;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void Vehicle::free()
{
    delete[]name;
}

Vehicle::Vehicle():Vehicle(0,0,0,0,",")
{
}

Vehicle::Vehicle(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int tires, const char* name):yearOfCreation(year),weight(weight),maxSpeed(maxSpeed),NumberOfTiresOrWagons(tires)
{
   this-> name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Vehicle::Vehicle(const Vehicle& other)
{
    copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Vehicle::~Vehicle()
{
}

unsigned int Vehicle::getYear() const
{
    return yearOfCreation;
}

unsigned int Vehicle::getWeight() const
{
    return weight;
}

unsigned int Vehicle::getSpeed() const
{
    return maxSpeed;
}

unsigned int Vehicle::getTires() const
{
    return NumberOfTiresOrWagons;
}

const char* Vehicle::getName() const
{
    return name;
}


void Vehicle::readFrom(std::istream& is) 
{
    char buffer[256];
    is >> yearOfCreation >> weight >> maxSpeed >> NumberOfTiresOrWagons >> buffer;

    this->name = new char[strlen(buffer) + 1];
    strcpy(this->name, buffer);
}

void Vehicle::writeTo(std::ostream& os)const
{
    os << yearOfCreation << " " << weight << " " << maxSpeed << " "
        << NumberOfTiresOrWagons << " " << name;
}

void Vehicle::print()const {
    std::cout<< yearOfCreation << " " << weight << " " << maxSpeed << " "
        << NumberOfTiresOrWagons << " " << name;
}