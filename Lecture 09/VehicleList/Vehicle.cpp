#include "Vehicle.h"

void Vehicle::copyFrom(const Vehicle& other)
{
    if (other.description) {
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);
    }
    else
    {
        description = nullptr;
    }

}

void Vehicle::free()
{
    delete[]description;
}

Vehicle::Vehicle(const Vehicle& other) :regNumber(other.regNumber)
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

Vehicle::Vehicle(const Registration& number, const char* descr)
    :regNumber(number)
{

    delete[]description;
    description = new char[strlen(descr) + 1];
    strcpy(description, descr);
    
}

Vehicle::~Vehicle()
{
    free();
}

const Registration& Vehicle::getRegistration() const
{
    return regNumber;
}

const char* Vehicle::getDescription() const
{
    return description;
}
