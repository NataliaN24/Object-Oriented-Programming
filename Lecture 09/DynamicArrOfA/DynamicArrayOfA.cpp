#include "DynamicArrayOfA.h"

static size_t closestPowerOfAwo(size_t n)
{
    n--;

    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;

    return n + 1;
};
void DynamicArrayOfA::copyfrom(const DynamicArrayOfA& other)
{
    arr = new A[other.capacity];
    for (int i = 0; i < other.size; i++)
    {
        arr[i] = other.arr[i];
    }
    capacity = other.capacity;
    size = other.size;
}

void DynamicArrayOfA::movefrom(DynamicArrayOfA&& other)
{
    arr = other.arr;
    size = other.size;
    capacity = other.capacity;

    other.arr = nullptr;
    other.capacity = 0;
    other.size = 0;
}

void DynamicArrayOfA::free()
{
    delete[]arr;
    arr = nullptr;
    capacity = 0;
    size = 0;
}

void DynamicArrayOfA::resize(size_t newCap)
{
    A* newArr = new A[newCap];
    for (int i = 0; i < newCap; i++)
    {
        newArr[i] = arr[i];
    }
    capacity = newCap;
    delete[]arr;
    arr = newArr;
}

DynamicArrayOfA::DynamicArrayOfA():DynamicArrayOfA(8)
{
}

DynamicArrayOfA::DynamicArrayOfA(size_t capacity)
{
    this->capacity = closestPowerOfAwo(capacity);
    arr = new A[this->capacity];
}

DynamicArrayOfA::DynamicArrayOfA(const DynamicArrayOfA& other)
{
    copyfrom(other);
}

DynamicArrayOfA& DynamicArrayOfA::operator=(const DynamicArrayOfA& other)
{
    if (this != &other)
    {
        free();
        copyfrom(other);
    }
    return *this;
}

DynamicArrayOfA::~DynamicArrayOfA()
{
    free();
}

DynamicArrayOfA::DynamicArrayOfA(DynamicArrayOfA&& other) noexcept
{
    movefrom(std::move(other));
}

DynamicArrayOfA& DynamicArrayOfA::operator=(DynamicArrayOfA&& other) noexcept
{
    if (this != &other)
    {
        free();
        movefrom(std::move(other));
    }
    return *this;

}

void DynamicArrayOfA::pushBack(const A& newEl)
{
    if (size >= capacity)
    {
        resize(capacity * 2);
    }
    arr[size++] = newEl;
}

void DynamicArrayOfA::pushBack(A&& newEl)
{
    if (size >= capacity)
    {
        resize(capacity * 2);
    }
    arr[size++] = std::move(newEl);
}

void DynamicArrayOfA::popBack()
{
    if (size)
    {
        size--;
    }
    else
    {
        throw std::length_error("Already empty!");
    }
    if (size * 4 <= capacity && capacity > 1) {
        resize(capacity / 2);
    }
}

void DynamicArrayOfA::setAtIndex(const A& el, size_t index)
{
    if (index >= size)
    {
        throw std::length_error("No such index!");
    }
    arr[index] = el;
}

void DynamicArrayOfA::setAtIndex(A&& el, size_t index)
{
    if (index >= size)
    {
        throw std::length_error("No such index!");
    }
    arr[index] = std::move(el);
}

size_t DynamicArrayOfA::getSize() const
{
    return size;
}

bool DynamicArrayOfA::isEmpty() const
{
    return size == 0;
}

const A& DynamicArrayOfA::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::length_error("No such index!");
    }
    return arr[index];
    
}

A& DynamicArrayOfA::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::length_error("No such index!");
    }
    return arr[index];
}
