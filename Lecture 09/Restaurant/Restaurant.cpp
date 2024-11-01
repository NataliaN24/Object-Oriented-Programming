#include "Restaurant.h"

void Restaurant::free()
{
    delete[]list;
    count = 0;
}

void Restaurant::copyFrom(const Restaurant& other)
{
    if (std::strlen(other.name) >= MAX_LENGTH)
    {
        throw std::out_of_range("Name too long!");
    }
    std::strcpy(this->name, other.name);
    list = new Product[other.count];
    for (int i = 0; i < other.count; i++)
    {
        list[i] = other.list[i];
    }
    count = other.count;
}

void Restaurant::moveFrom(Restaurant&& other)
{
    if (std::strlen(other.name) >= MAX_LENGTH)
    {
        throw std::out_of_range("Name too long!");
    }

    std::strcpy(this->name, other.name);
    list = other.list;
    count = other.count;

    std::strcpy(other.name," ");
    other.list = nullptr;
    other.count = 0;

}

Restaurant::Restaurant():count(0),list(nullptr)
{
    name[0] = '\0';
}

Restaurant::Restaurant(const Restaurant& other)
{
    copyFrom(other);
}

Restaurant::Restaurant(Restaurant&& other) noexcept
{
    moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Restaurant::~Restaurant()
{
    free();
}

Restaurant::Restaurant(const char* name, Product* list, size_t count)
{
    if (std::strlen(name) >= MAX_LENGTH)
    {
        throw std::out_of_range("Name too long!");
    }
    std::strcpy(this->name,name);
    this->count = count;
    this->list = new Product[this->count];
    for (int i = 0; i < count; i++)
    {
        this->list[i] = list[i];
    }
  

}

void Restaurant::addProduct(const Product& newProduct)
{
    Product* newList = new Product[count + 1];
    for (size_t i = 0; i < count; ++i) {
        newList[i] = list[i];
    }
    newList[count] = newProduct;
    delete[] list;
    list = newList;
    ++count;
}

bool Restaurant::getOrder(const Order& order)
{
    if (strcmp(this->name, order.getName().c_str()) != 0)
    {
        throw std::runtime_error("Restaurant name does not match!");
    }
    {
        for (int i = 0; i < order.getCount(); i++)
        {
            bool found = false;
            for (int j = 0; j < count; j++)
            {
                if (strcmp(list[j].getName().c_str(), order.getList()[i].getName().c_str()) == 0)
                {
                    found = true;
                    break;

                }
            }

            if (!found)
            {
                throw std::runtime_error("Error! Product not available in this restaurant!");
            }
        }

        return true;
    }
}

const char* Restaurant::getRestaurantName() const
{
    return name;
}

const Product* Restaurant::getList() const
{
    return list;
}

size_t Restaurant::getCount() const
{
    return count;
}