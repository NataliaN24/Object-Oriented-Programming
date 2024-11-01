#include "Order.h"

void Order::free()
{
    delete[]list;
    product_count = 0;
}

void Order::copyFrom(const Order& other)
{
    this->restaurant_name = other.restaurant_name;
    this->product_count = other.product_count;
    this->list = new Product[product_count];
    for (int i = 0; i < product_count; i++)
    {
        this->list[i] = other.list[i];
    }
}

void Order::moveFrom(Order&& other)
{
    restaurant_name = std::move(other.restaurant_name);
    this->product_count = other.product_count;
    this->list = other.list;

    other.restaurant_name = nullptr;
    other.product_count = 0;
    other.list = nullptr;

}

Order::Order():restaurant_name(),product_count(0)
{
    list = new Product[product_count];
    list = nullptr;
}

Order::Order(const Order& other)
{
    copyFrom(other);
}

Order::Order(Order&& other) noexcept
{
    moveFrom(std::move(other));
}

Order& Order::operator=(const Order& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Order& Order::operator=(Order&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Order::~Order()
{
    free();
}

Order::Order(const MyString& name, size_t products, Product* list):restaurant_name(name),product_count(products)
{
    this->list = new Product[product_count];
    for (int i = 0; i < product_count; i++)
    {
        this->list[i] = list[i];
    }
}

void Order::addProduct(const Product& newProd)
{
    Product* newList = new Product[product_count + 1];
    for (size_t i = 0; i < product_count; ++i) {
        newList[i] = list[i];
    }
    newList[product_count] = newProd;
    delete[] list;
    list = newList;
    ++product_count;
}

unsigned Order::howManyTime()
{
    unsigned minutes = product_count;
    for (int i = 0; i < product_count; i++) {
        minutes += list->getLength();
    }
    return minutes;
}

const MyString Order::getName() const
{
    return restaurant_name;
}

size_t Order::getCount() const
{
    return product_count;
}

const Product* Order::getList() const
{
    return list;
}

const Product& Order::getProduct(int index)
{
    if (index >= product_count) {
        throw std::out_of_range("Error!");
    }
    return list[index];
}