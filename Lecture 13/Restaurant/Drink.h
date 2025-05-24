#pragma once
#include"RestaurantItem.h"

class Drink:public RestaurantItem
{
	char name[MAX_NAME_LEN + 1];//it should be const char*
	double alcohol;

public:
	Drink();
	Drink(const productType& type, size_t available, double price, const char* name, double alcohol);
	double getAlcohol()const;
	virtual RestaurantItem* clone()const override;
	virtual void print()const override;
	bool isNonAlcoholic() const override;


};
bool operator>(const Drink& left, const Drink& right);

