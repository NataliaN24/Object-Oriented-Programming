#include "DynamicArrayOfpointers.h"

void DynamicArrayOfPointers::free()
{
    for (int i = 0; i < count; i++)
    {
        delete data[i];
    }
    delete[]data;
}

void DynamicArrayOfPointers::copyFrom(const DynamicArrayOfPointers& other)
{
    data = new A*[other.capacity];
    for (int i = 0; i < other.count; i++)
    {
        if (other.data[i] = nullptr)
        {
            data[i] = nullptr;
        }
        else
        {
            data[i] = new A(*other.data[i]);
        }
    }
    capacity = other.capacity;
    count = other.count;
}

void DynamicArrayOfPointers::resize(size_t newCap)
{
    A** newDataPtr = new A * [newCap] {nullptr};

    for (int i = 0; i < capacity; i++)
        newDataPtr[i] = data[i];

    delete[] data;
    data = newDataPtr;

    capacity = newCap;
}

void DynamicArrayOfPointers::moveFrom(DynamicArrayOfPointers&& other)
{
    data = other.data;
    other.data = nullptr;

    capacity = other.capacity;
    count = other.count;

    other.count = 0;
}

int DynamicArrayOfPointers::getFirstFreeIndex() const
{
    for (int i = 0; i < capacity; i++)
    {
        if (data[i] = nullptr)
        {
            return i;
        }
    }
    return -1;
}

DynamicArrayOfPointers::DynamicArrayOfPointers()
{
    capacity = 8;
    data = new A * [capacity] {nullptr};
}

DynamicArrayOfPointers::DynamicArrayOfPointers(const DynamicArrayOfPointers& other)
{
    copyFrom(other);
}

DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(const DynamicArrayOfPointers& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

DynamicArrayOfPointers::~DynamicArrayOfPointers()
{
    free();
}

DynamicArrayOfPointers::DynamicArrayOfPointers(DynamicArrayOfPointers&& other) noexcept
{
    moveFrom(std::move(other));
}

DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(DynamicArrayOfPointers&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void DynamicArrayOfPointers::addAtFirstFreeIndex(const A& obj)
{
    if (count >= capacity)
    {
        resize(capacity * 2);
    }
    int index = getFirstFreeIndex();
    if (index == -1)
    {
        return;
    }
    data[index] = new A(obj);
    count++;
}

void DynamicArrayOfPointers::addAtFirstFreeIndex(A&& obj)
{
    if (count >= capacity)
    {
        resize(capacity * 2);
    }
    int index = getFirstFreeIndex();
    if (index == -1)
    {
        return ;
    }
    data[index] = new A(std::move(obj));
    count++;

}

bool DynamicArrayOfPointers::containsAt(unsigned ind) const
{
    return ind < capacity&& data[ind] != nullptr;
}

void DynamicArrayOfPointers::popBack()
{
    if (count == 0)
    {
        return;
    }
    delete data[count - 1];
    count--;
}

void DynamicArrayOfPointers::removeAt(size_t index)
{
    if (index >= capacity)
    {
        return;
    }
    delete data[index];
    data[index] = nullptr;
    count--;
}

void DynamicArrayOfPointers::setAtIndex(const A& obj, size_t index)
{
    if (index >= capacity)
    {
        resize(capacity * 2);
    }
    if (data[index] != nullptr)
    {
        data[index]->operator=(obj);
    }
    else
    {
        data[index] = new A(obj);
        count++;
    }
}

void DynamicArrayOfPointers::setAtIndex(A&& obj, size_t index)
{
    if (data[index] != nullptr)
        *data[index] = obj;
    else
    {
        data[index] = new A(std::move(obj));
        count++;
    }
}

size_t DynamicArrayOfPointers::size() const
{
    return count;
}

const A& DynamicArrayOfPointers::operator[](size_t index) const
{
    return *data[index];
}

A& DynamicArrayOfPointers::operator[](size_t index)
{
    return *data[index];
}