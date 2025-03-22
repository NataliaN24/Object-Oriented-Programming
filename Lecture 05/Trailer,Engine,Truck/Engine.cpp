#include "Engine.h"

Engine::Engine()
{
    currentFuelConsumption = 0;
}

Engine::Engine(double _currentFuelConsumption)
{
    setCurrentFuel(_currentFuelConsumption);
}


void Engine::setCurrentFuel(double newCurrentFuel)
{
    if (newCurrentFuel <= tankVolume && newCurrentFuel>=0)
    {
        currentFuelConsumption = newCurrentFuel;
    }
    else
    {
        throw std::out_of_range("Invalid fuel level!");
    }
}


unsigned int Engine::getPower() const
{
    return power;
}

double Engine::getFuelConsumption() const
{
    return fuelConsumption;
}

double Engine::getCurrentFuelConsumtpion() const
{
    return currentFuelConsumption;
}

double Engine::getTankVolume() const
{
    return tankVolume;
}

void Engine::refuel(double liters)
{
    if (liters < 0)
    {
        throw std::invalid_argument("Cannot refuel with a negative amount!");
    }

    double addedFuel = liters + currentFuelConsumption;
    if (addedFuel <= tankVolume)
    {
        setCurrentFuel(addedFuel);
    }
    else
    {
        throw std::out_of_range("error!");
    }
}

void Engine::drive(double km)
{
    double fuelNeeded = (km / 100) * fuelConsumption;
    if (fuelNeeded <= currentFuelConsumption)
    {
        currentFuelConsumption -= fuelNeeded;
    }
    else
    {
        throw std::out_of_range("Not enough fuel to drive this distance!");
    }
}

double Engine::getRemainingRange() const
{
    return (currentFuelConsumption / fuelConsumption) * 100;
}
