#pragma once
#include<iostream>
#pragma warning(disable :4996)

constexpr int MAX_NAME_LEN = 50;

enum class productType
{
	food,//0
	drink,//1
	nothing
};

class RestaurantItem
{
	productType type;
	size_t availability;
	double price;
	char name[MAX_NAME_LEN + 1];//it should be const char*

public:
	RestaurantItem();
	RestaurantItem(const productType& type, size_t available, double price,const char*name);
	virtual ~RestaurantItem()=default;

	void setType(const productType& type);
	void setAvailability(size_t availability);
	void setPrice(double price);
	void setName(const char* name);

	productType getType()const;
	size_t getAvailibility()const;
	double getPrice()const;
	const char* getName()const;
	virtual RestaurantItem* clone() const = 0;
	virtual void print()const = 0;

	virtual bool isNonAlcoholic() const;

};