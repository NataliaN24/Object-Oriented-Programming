#include "Commander.h"

void Commander::copyFrom(const Commander& other)
{
    
    soldiers = new Soldier[other.count];
    for (int i = 0; i < other.count; i++)
    {
        soldiers[i] = other.soldiers[i];
    }
    count = other.count;
}

void Commander::free()
{
    delete[]soldiers;
    soldiers = nullptr;
    count = 0;
}

Commander::Commander():soldiers(nullptr),count(0)
{
}

Commander::Commander(const char* name, size_t age, size_t combat, size_t salary, size_t count, const Soldier* battalion):Soldier(name,age,combat,salary)
{
    setBattalion(battalion, count);
}

Commander::Commander(const Commander& other):Soldier(other)
{
    copyFrom(other);
}

Commander& Commander::operator=(const Commander& other)
{
    if (this != &other) {
        Soldier::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Commander::~Commander()
{
    free();
}

void Commander::setBattalion(const Soldier* soldiers,size_t count)
{
    this->soldiers = new Soldier[count];
    for (int i = 0; i < count; i++)
    {
        this->soldiers[i] = soldiers[i];
    }
    this->count = count;
}

Soldier* Commander::getBattalion() const
{
    return soldiers;
}

size_t Commander::getNumOfSoldiers() const
{
    return count;
}

void Commander::print() const
{
    Soldier::print();//prints info for command
    for (int i = 0; i < count; i++)
    {
        soldiers[i].print();//print info for each soldier
    }
}
