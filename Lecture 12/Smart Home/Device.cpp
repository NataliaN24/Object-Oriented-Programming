#include "Device.h"

Device::Device():name(""),producer(" "),price(0)
{
}

Device::Device(const MyString& _name, const MyString& prod, size_t pr)
{
    this->name = _name;
    this->producer = prod;
    this->price = pr;
}

Device::~Device()
{
}

const char* Device::getName() const
{
    return name.c_str();
}

const char* Device::getProducer() const
{
    return producer.c_str();
}



size_t Device::getPrice() const
{
    return price;
}
