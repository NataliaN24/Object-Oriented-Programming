#include "Gadget.h"

Gadget::Gadget(const MyString& model, double price):model(model),price(price)
{
}

const MyString& Gadget::getmodel() const
{
    return model;
}

void Gadget::setModel(const MyString& model)
{
    this->model = model;
}

double Gadget::getPrice() const
{
    return price;
}

void Gadget::setPrice(double newPrice)
{
    this->price = newPrice;
}
