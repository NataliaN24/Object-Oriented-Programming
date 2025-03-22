#pragma once
#include <iostream>

constexpr unsigned int MAX_POWER = 100;
constexpr double FUEL_CONSUMPTION=5.5;
constexpr double TANK_VOLUME = 50.0;

class Engine
{
	const unsigned int power=MAX_POWER;
	const double fuelConsumption= FUEL_CONSUMPTION;
	double tankVolume = TANK_VOLUME;
	double currentFuelConsumption=0.0;
	
public:
	Engine();
	Engine(double _currentFuelConsumption);
	
	void setCurrentFuel(double newCurrentFuel);

	unsigned int getPower()const;
	double getFuelConsumption()const;
	double getCurrentFuelConsumtpion()const;
	double getTankVolume()const;

	void refuel(double liters);
	void drive(double km);
	double getRemainingRange()const;

};

