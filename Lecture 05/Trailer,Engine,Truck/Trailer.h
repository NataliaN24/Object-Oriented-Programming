#pragma once
#include<iostream>

constexpr double MAX_LOAD = 50;

class Trailer
{
	const double maxLoad=MAX_LOAD;
	double currentLoad=0;
	double area=0;
public:
	Trailer();
	Trailer( double _currentLoad, double _area);
	void setCurrentLoad(double newCurrentLoad);
	void setArea(double newArea);
	double getMaxLoad()const;
	double getCurrentLoad()const;
	double getArea()const;
	void addLoad(double weight);
};