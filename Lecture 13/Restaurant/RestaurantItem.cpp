#include "RestaurantItem.h"

RestaurantItem::RestaurantItem():type(productType::nothing),availability(0),price(0.0)
{
}

RestaurantItem::RestaurantItem(const productType& type, size_t available, double price,const char *name):type(type),availability(available),price(price)
{
    setName(name);
}

void RestaurantItem::setType(const productType& type)
{
    this->type = type;
}

void RestaurantItem::setAvailability(size_t availability)
{
    this->availability = availability;
}

void RestaurantItem::setPrice(double price)
{
    this->price = price;
}

productType RestaurantItem::getType() const
{
    return type;
}

size_t RestaurantItem::getAvailibility() const
{
    return availability;
}

double RestaurantItem::getPrice() const
{
    return price;
}

void RestaurantItem::setName(const char* name) {
    strcpy(this->name, name);
}

const char* RestaurantItem::getName()const {
    return name;
}

bool RestaurantItem:: isNonAlcoholic() const 
{ 
    return true;
}