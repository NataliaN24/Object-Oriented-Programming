#include"RestaurantItem.h"
#include"Drink.h"
#include"Food.h"

#pragma once

class Restaurant {
	RestaurantItem** items;
	int count;
	int capacity;
	
	void copyFrom(const Restaurant& other);
	void free();
	void resize();
public:
	Restaurant();
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	~Restaurant();

	bool addProduct(const RestaurantItem* product);
	bool removeProduct(int index);
	bool changePrice(int index, double price);
	bool changeName(int index, const char* name);
	void printAll()const;
	void printAllNonAlcohol()const;

};