#pragma once
#include"Engine.h"
#include "Trailer.h"
#pragma warning(disable:4996)

class Truck
{
	char* name;
	double weight;
	Engine* engine;
	Trailer* trailer;

	void copyFrom(const Truck& other);
	void free();

public:
	Truck();
	Truck(const char* name, double weight,  Engine* engine, Trailer* trailer);
	Truck(const Truck& other);
	Truck& operator=(const Truck& other);
	~Truck();

	void setName(const char* newName);
	const char* getName()const;
	void setWeight(double newWeight);
	double getWeight()const;
	void setEngine( Engine* engine);
	Engine *getEngine()const;
	void setTrailer(Trailer* trailer);
	Trailer *getTrailer()const;

	void attachTrailer(Trailer* trailer);
	bool hasTrailer()const;
	void detachTrailer();
	void drive(double km);
	void loadTruck(double weight);
	void changeEngine(Engine* newEngine);

};

