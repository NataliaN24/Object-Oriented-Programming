#pragma once
#include<cstring>
#include"Restaurant.h"
#include"Product.h"
#include"Order.h"
#pragma warning(disable:4996)

class FoodPanda
{
	Restaurant* restaurants;
	size_t size;

	void free();
	void copyFrom(const FoodPanda& other);
	void moveFrom(FoodPanda&& other);
public:
	FoodPanda();
	FoodPanda(const FoodPanda& other);
	FoodPanda(FoodPanda&& other)noexcept;
	FoodPanda& operator=(const FoodPanda& other);
	FoodPanda& operator=(FoodPanda&& other)noexcept;
	~FoodPanda();

	FoodPanda(Restaurant* res, size_t size);
	void addProductToRestaurant(const Product& prod, Restaurant&res);
	void addRestaurant(const Restaurant& res);
	void addOrder(const Order& order, Restaurant& res);

};