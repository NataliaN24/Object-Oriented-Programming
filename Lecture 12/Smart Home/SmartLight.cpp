#include "SmartLight.h"

SmartLight::SmartLight():brightnessLevel(0)
{

}

SmartLight::SmartLight(const MyString& name, const MyString& producer, size_t price, int bright):Device(name,producer,price),brightnessLevel(bright)
{
}

int SmartLight::getBrightness() const
{
    return brightnessLevel;
}

void SmartLight::turnOn()const
{
    std::cout << "Smart Light is turned on" << std::endl;
}

void SmartLight::turnOff()const
{
    std::cout << "Smart Light is turned off" << std::endl;
}

void SmartLight::printDetails() const
{
    std::cout << "Name:" << getName() << '\n'
        << "Producer:" << getProducer() << "\n"
        << "Price:" << getPrice() << '\n'
        << getBrightness() << std::endl;
}

Device* SmartLight::clone() const
{
    return new SmartLight(*this);
}
