#include "Food.h"

Food::Food() :Food(productType::food, 0, 0,"",0) {

}

Food::Food(const productType& type, size_t available, double price, const char* name, double amount):RestaurantItem(type,available,price,name)
{

	this->amount = amount;
}


double Food::getAmount()const { 
	return amount; 
}

RestaurantItem* Food::clone() const 
{
	return new Food(*this);
}
void Food::print()const
{
	std::cout << (int)getType() << " " << getAvailibility() << " " << getAmount() << " " << getPrice() << " " << getName();
}
bool operator>(const Food& left, const Food& right)
{
	return left.getAmount() > right.getAmount();
}
