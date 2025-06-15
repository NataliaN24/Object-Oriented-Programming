#include "Store.h"

void Store::free()
{
    for (int i = 0; i < size; i++)
    {
        delete gadgets[i];
    }
    delete[]gadgets;
}

void Store::resize()
{
    capacity *= 2;
    Gadget** newGadgets = new Gadget * [capacity];
    for (int i = 0; i < size; i++)
        newGadgets[i] = gadgets[i];

    delete[] gadgets;
    gadgets = newGadgets;
}

Store::Store()
{
    capacity = 8;
    size = 0;
    gadgets = new Gadget * [capacity];
}


Store& Store::getInstance()
{
    static Store instance;
    return instance;
}

Store::~Store()
{
    free();
}

void Store::sellProduct(const Gadget& obj)
{
    for (int i = 0; i < size; i++)
    {
        if (gadgets[i]->getmodel() == obj.getmodel())
        {
            delete gadgets[i];
            // Преместване наляво
            for (int j = i; j < size - 1; j++)
                gadgets[j] = gadgets[j + 1];
            size--;
            return;
        }
    }

}

void Store::buyProduct(const Gadget& obj)
{
    if (size >= capacity)
    {
        resize();
    }
    gadgets[size++] = obj.clone();

}

void Store::printAll()const
{
    for (int i = 0; i < size; i++)
    {
        gadgets[i]->print();
        std::cout << std::endl;
    }
}
