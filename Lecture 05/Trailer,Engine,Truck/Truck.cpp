#include "Truck.h"

void Truck::copyFrom(const Truck& other)
{
	name = new char[strlen(other.name) + 1];
	std::strcpy(name, other.name);
	weight = other.weight;
	engine = new Engine(*other.engine);//if it was engine=other.engine we are copying the pointer not the actual object
	trailer = new Trailer(*other.trailer);
}

void Truck::free()
{
	delete[]name;
	delete engine;
	delete trailer;
	weight = 0;
}

Truck::Truck()
{
	this->name = new char[strlen("Default truck") + 1];
	strcpy(this->name, "Default truck");
	weight = 0.0;
	engine = new Engine();
	trailer = nullptr;
}

Truck::Truck(const char* name, double weight,  Engine* engine,  Trailer* trailer)
{
	setName(name);
	setWeight(weight);
	setEngine(engine);
	setTrailer(trailer);
}

Truck::Truck(const Truck& other)
{
	copyFrom(other);
}

Truck& Truck::operator=(const Truck& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Truck::~Truck()
{
	free();
}

void Truck::setName(const char* newName)
{
	if (newName != nullptr)
	{
		delete[]name;
		name = new char[strlen(newName) + 1];
		strcpy(name, newName);
	}
}

const char* Truck::getName() const
{
	return name;
}

void Truck::setWeight(double newWeight)
{
	if (weight != newWeight)
	{
		weight = newWeight;
	}
}

double Truck::getWeight() const
{
	return weight;
}

void Truck::setEngine(Engine* engine)
{
	if (this->engine != nullptr)
	{
		delete this->engine;
	}
	if (engine != nullptr)
	{
		this->engine = engine;
	}	
}

Engine* Truck::getEngine() const
{
	return engine;
}

void Truck::setTrailer(Trailer* trailer)
{
	if (this->trailer != nullptr)
	{
		delete this->trailer;
	}
	if (trailer != nullptr)
	{
		this->trailer = trailer;
	}
}

Trailer *Truck::getTrailer() const
{
	return trailer;
}

void Truck::attachTrailer(Trailer* trailer)
{
	setTrailer(trailer);
}

bool Truck::hasTrailer() const
{
	if (trailer != nullptr)
	{
		return true;
	}
	return false;
}

void Truck::detachTrailer()
{
	trailer = nullptr;
}

void Truck::drive(double km)
{
	engine->drive(km);
}

void Truck::loadTruck(double weight)
{
	if (trailer == nullptr)
	{
		return;
	}
	trailer->addLoad(weight);
}

void Truck::changeEngine(Engine* newEngine)
{
	setEngine(newEngine);
}