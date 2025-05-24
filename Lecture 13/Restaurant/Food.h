#pragma once
#pragma warning(disable :4996)
#include"RestaurantItem.h"


class Food:public RestaurantItem
{
		double amount;
public:
	Food();
	Food(const productType& type, size_t available, double price, const char* name, double amount);
	double getAmount()const;
	virtual RestaurantItem* clone() const override;
	virtual void print()const override;


};
bool operator>(const Food& left, const Food& right);
