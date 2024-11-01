#pragma once
#include<iostream>
#include"MyString.h"
#include"Product.h"

class Order
{
	MyString restaurant_name;
	size_t product_count;
	Product* list;

	void free();
	void copyFrom(const Order&other);
	void moveFrom(Order&&other);

public:
	Order();
	Order(const Order& other);
	Order(Order&& other)noexcept;
	Order& operator=(const Order& other);
	Order& operator=(Order&& other)noexcept;
	~Order();

	Order(const MyString& name, size_t products, Product* list);
	void addProduct(const Product& newProd);
	unsigned howManyTime();

	const MyString getName()const;
	size_t getCount()const;
	const Product* getList()const;
	const Product& getProduct(int index);
};