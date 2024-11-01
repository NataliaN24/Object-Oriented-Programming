#include "FoodPanda.h"

void FoodPanda::free()
{
    delete[] restaurants;
    size = 0;
}

void FoodPanda::copyFrom(const FoodPanda& other)
{
    size = other.size;
    restaurants = new Restaurant[size];
    for (size_t i = 0; i < size; i++) {
        restaurants[i] = other.restaurants[i];
    }
}

void FoodPanda::moveFrom(FoodPanda&& other)
{
    restaurants = other.restaurants;
    size = other.size;
    other.restaurants = nullptr; 
    other.size = 0;
}

FoodPanda::FoodPanda():restaurants(nullptr),size(0)
{
}

FoodPanda::FoodPanda(const FoodPanda& other)
{
    copyFrom(other);
}

FoodPanda::FoodPanda(FoodPanda&& other) noexcept
{
    moveFrom(std::move(other));
}

FoodPanda& FoodPanda::operator=(const FoodPanda& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

FoodPanda& FoodPanda::operator=(FoodPanda&& other) noexcept
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

FoodPanda::~FoodPanda()
{
    free();
}

FoodPanda::FoodPanda(Restaurant* res, size_t size):size(size)
{
    res = new Restaurant[size];
    for (size_t i = 0; i < size; i++) {
        restaurants[i] = res[i];
    }
}

void FoodPanda::addProductToRestaurant(const Product& prod ,  Restaurant& res)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(restaurants[i].getRestaurantName(), res.getRestaurantName()) == 0)
        {
            found = true;
            restaurants[i].addProduct(prod);
            break;
        }
    }
    if (!found)
    {
        throw std::runtime_error("No such restaurant!");
    }
   
}

void FoodPanda::addRestaurant(const Restaurant& res)
{
    Restaurant* newRestaurants = new Restaurant[size + 1];
    for (size_t i = 0; i < size; i++) {
        newRestaurants[i] = restaurants[i]; 
    }
    newRestaurants[size] = res;
    delete[] restaurants; 
    restaurants = newRestaurants; 
    size++;
}

void FoodPanda::addOrder(const Order& order, Restaurant& res)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(restaurants[i].getRestaurantName(), res.getRestaurantName()) == 0)
        {
            found = true;
            restaurants[i].getOrder(order);
            break;
        }
    }
    if (!found)
    {
        throw std::runtime_error("No such restaurant!");
    }
}