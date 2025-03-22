#include "Trailer.h"

Trailer::Trailer()
{
}

Trailer::Trailer( double _currentLoad, double _area)
{
	setCurrentLoad(_currentLoad);
	setArea(_area);
}

void Trailer::setCurrentLoad(double newCurrentLoad)
{
	if (newCurrentLoad <= maxLoad && currentLoad != newCurrentLoad)
	{
		currentLoad = newCurrentLoad;
	}	
}

void Trailer::setArea(double newArea)
{
	area = newArea;
}

double Trailer::getMaxLoad() const
{
	return maxLoad;
}

double Trailer::getCurrentLoad() const
{
	return currentLoad;
}

double Trailer::getArea() const
{
	return area;
}

void Trailer::addLoad(double weight)
{
	double addedLoad = currentLoad + weight;
	if (addedLoad <= maxLoad)
	{
		setCurrentLoad(addedLoad);
	}
	else
	{
		throw std::out_of_range("To much load!");
	}
}