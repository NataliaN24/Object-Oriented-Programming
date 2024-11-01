#pragma once
#include"Product.h"
#include<cstring>
#include"Order.h"
#pragma warning(disable:4996)

constexpr int MAX_LENGTH = 25;

class Restaurant
{
	char name[MAX_LENGTH + 1];
	Product* list;
	size_t count;

	void free();
	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
public:
	Restaurant();
	Restaurant(const Restaurant& other);
	Restaurant(Restaurant&& other)noexcept;
	Restaurant& operator=(const Restaurant& other);
	Restaurant& operator=(Restaurant&& other)noexcept;
	~Restaurant();

	Restaurant(const char* name, Product* list, size_t count);
	void addProduct(const Product& newProduct);
	bool getOrder(const Order& order);
	const char* getRestaurantName()const;
	const Product* getList()const;
	size_t getCount()const;

};