#include"Restaurant.h"

Restaurant::Restaurant() : count(0), capacity(4) {
	items = new RestaurantItem * [capacity];
}
void Restaurant::free() {
	for (int i = 0; i < count; ++i)
		delete items[i];
	delete[] items;
	count = 0;
	capacity = 0;
}

void Restaurant::copyFrom(const Restaurant& other) {
	count = other.count;
	capacity = other.capacity;
	items = new RestaurantItem * [capacity];
	for (int i = 0; i < count; ++i)
		items[i] = other.items[i]->clone();
}

void Restaurant::resize() {
	capacity *= 2;
	RestaurantItem** newItems = new RestaurantItem * [capacity];
	for (int i = 0; i < count; ++i)
		newItems[i] = items[i];
	delete[] items;
	items = newItems;
}

Restaurant::Restaurant(const Restaurant& other) {
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Restaurant::~Restaurant() {
	free();
}
bool Restaurant::addProduct(const RestaurantItem* product) {
	if (count == capacity)
	{
		resize();
	}
	items[count++] = product->clone();
	return true;
}
bool Restaurant::removeProduct(int index) {
	if (index < 0 || index >= count)
		return false;
	delete items[index];
	for (int i = index; i < count-1; i++)
	{
		items[i] = items[i + 1];
	}
	--count;
	return true;
}

bool Restaurant::changePrice(int index, double price)
{
	if (index < 0 || index >= count)
		return false;
	items[index]->setPrice(price);
	return true;
}
bool  Restaurant::changeName(int index, const char* name) 
{
	if (index < 0 || index >= count)
		return false;
	items[index]->setName(name);
	return true;
}
	
void  Restaurant::printAll()const {
	for (int i = 0; i < count; i++)
	{
		items[i]->print();
	}

}
void  Restaurant::printAllNonAlcohol()const 
{
	for (int i = 0; i < count; i++)
	{
		if (items[i]->getType() == productType::drink && items[i]->isNonAlcoholic())
		{
			items[i]->print();
		}
	}

}