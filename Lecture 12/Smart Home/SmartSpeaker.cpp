#include "SmartSpeaker.h"

SmartSpeaker::SmartSpeaker():volume(0)
{
}

SmartSpeaker::SmartSpeaker(const MyString& name, const MyString& producer, size_t price, size_t vol):Device(name, producer, price), volume(vol)
{
}

size_t SmartSpeaker::getVolume() const
{
    return volume;
}

void SmartSpeaker::turnOn() const
{
    std::cout << "Smart Speaker is turned on" << std::endl;
}

void SmartSpeaker::turnOff() const
{
    std::cout << "Smart Speaker is turned off" << std::endl;
}

void SmartSpeaker::printDetails() const
{

    std::cout << "Name:" << getName() << '\n'
        << "Producer:" << getProducer() << "\n"
        << "Price:" << getPrice() << '\n'
        << getVolume() << std::endl;
}

Device* SmartSpeaker::clone() const
{
    return new SmartSpeaker(*this);
}
