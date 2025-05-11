#include "SmartThermostat.h"

SmartThermostat::SmartThermostat():Device(),currentTemp(0),desiredTemp(0)
{
}

SmartThermostat::SmartThermostat(const MyString& name, const MyString& producer, size_t price, int currentTemp, int desiredTemp):Device(name, producer, price)
,currentTemp(currentTemp),desiredTemp(desiredTemp)
{
}

int SmartThermostat::getCurrentTemp() const
{
    return currentTemp;
}

int SmartThermostat::getDesiredTemp() const
{
    return desiredTemp;
}

void SmartThermostat::turnOn() const
{
    std::cout << "Smart Thermostat is turned on" << std::endl;
}

void SmartThermostat::turnOff() const
{
    std::cout << "Smart Thermostat is turned off" << std::endl;
}

void SmartThermostat::printDetails() const
{
    std::cout << "Name:" << getName() << '\n'
        << "Producer:" << getProducer() << "\n"
        << "Price:" << getPrice() << '\n'
        << getCurrentTemp() <<" "<<getDesiredTemp()<< std::endl;
}

Device* SmartThermostat::clone() const
{
    return new SmartThermostat(*this);
}
