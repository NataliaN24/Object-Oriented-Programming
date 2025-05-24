#include "Drink.h"

Drink::Drink():Drink(productType::drink,0,0.0," ",0.0){}
Drink::Drink(const productType& type, size_t available, double price, const char* name, double alcohol) :RestaurantItem(type, available, price,name)
{
	this->alcohol = alcohol;
}

double Drink::getAlcohol()const
{
	return alcohol;
}
RestaurantItem* Drink::clone()const 
{
	return new Drink(*this);
 }
void Drink::print()const
{
	std::cout<<(int)getType() << " " << getAvailibility() << " "<< getAlcohol() << " " << getPrice() << " " << getName();
 }

bool operator>(const Drink& left, const Drink& right)
{
	return left.getAlcohol() > right.getAlcohol();
}

bool Drink::isNonAlcoholic() const {
	return getAlcohol() == 0.0;
}