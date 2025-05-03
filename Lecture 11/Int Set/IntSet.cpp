#include "IntSet.h"

void IntSet::copyFrom(const IntSet& other)
{
    count = other.count;
    numbers = new int[count];
    for (int i = 0; i < count; i++)
    {
        numbers[i] = other.numbers[i];
    }
}

void IntSet::free()
{
    delete[]numbers;
    numbers = nullptr;
}

IntSet::IntSet()
{
    count = 0;
    numbers = new int[count];
}

IntSet::IntSet(const IntSet& other)
{
    copyFrom(other);
}

IntSet& IntSet::operator=(const IntSet& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

IntSet::IntSet(const int* numbers, int cnt)
{
    count = cnt;
    this->numbers = new int[count];
    for (int i = 0; i < count; i++)
    {
        this->numbers[i] = numbers[i];
    }
}

IntSet::~IntSet()
{
    free();
}

bool IntSet::member(int x) const
{
    for (int i = 0; i < count; i++)
    {
        if (numbers[i] == x)
        {
            return true;
        }
    }
    return false;
}

int IntSet::get(int i) const
{
    if (!numbers)
        throw std::logic_error("numbers is not initialized");

    if (i < 0 || i >= count)
        throw std::out_of_range("Index out of range");

    return numbers[i];
}


bool IntSet::isSubsetOf(const IntSet& other)const
{
    for (int i = 0; i < count; i++)
    {
        if (!other.member(numbers[i]))
        {
            return false;
        }
        
    }
    return true;
}

bool IntSet::intersects(const IntSet& other)const
{
    for (int i = 0; i < count; i++)
    {
        if (other.member(numbers[i]))
        {
            return true;
        }
    }
    return false;
}
