#include "NumberSeries.h"
#include<iostream>

void NumberSeries::resize()
{
    capacity *= 2;
    int *newValueArray = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        newValueArray[i] = generatedValues[i];
    }
    delete[]generatedValues;
    generatedValues = newValueArray;

}

void NumberSeries::resetSeries()
{
    delete[]generatedValues;
    capacity = 10;
    size = 1;
    generatedValues = new int[capacity];
    generatedValues[0] = startValue;
}

void NumberSeries::copyFrom(const NumberSeries& other)
{
    startValue = other.startValue;
    capacity = other.capacity;
    func = other.func;
    size = other.size;
    generatedValues = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        generatedValues[i] = other.generatedValues[i];
    }
}

void NumberSeries::moveFrom(NumberSeries&& other)
{
    startValue = other.startValue;
    capacity = other.capacity;
    size = other.size;
    generatedValues = other.generatedValues;
    func = other.func;

    other.startValue = 0;
    other.capacity = 0;
    other.size = 0;
    other.generatedValues = nullptr;
    other.func = nullptr;

}

void NumberSeries::free()
{
    delete[]generatedValues;
}

NumberSeries::NumberSeries()
{
    startValue = 0;
    size = 0;
    capacity = 10;
    generatedValues = new int[capacity];
    func = nullptr;
}

NumberSeries::NumberSeries(const NumberSeries& other)
{
    copyFrom(other);
}

NumberSeries::NumberSeries(NumberSeries&& other) noexcept
{
    moveFrom(std::move(other));
}

NumberSeries& NumberSeries::operator=(const NumberSeries& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

NumberSeries& NumberSeries::operator=(NumberSeries&& other) noexcept
{
    if (this != &other) 
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

NumberSeries::~NumberSeries()
{
    free();
}

NumberSeries::NumberSeries(int initialValue, int(*function)(int)):startValue(initialValue),func(function),capacity(10),size(1)
{
    generatedValues = new int[capacity];
    generatedValues[0] = initialValue;
}

bool NumberSeries::contains(int number)
{
    for (int i = 0; i < size; i++)
    {
        if (generatedValues[i] == number)
        {
            return true;
        }
   }
    int current = generatedValues[size - 1];
    while (current < number)
    {
        current = func(current);
        if (size == capacity)
        {
            resize();
        }
        generatedValues[size++] = current;
        if (current == number)
        {
            return true;
        }
    }
    return current == number;
}

int NumberSeries::getElement(int i)
{
    if (i < size)
    {
        return generatedValues[i];
    }
    while(size<=i)
    {
        if (size == capacity)
        {
            resize();
        }
        generatedValues[size++] = func(generatedValues[size - 1]);
    }
    return generatedValues[i];
}

void NumberSeries::setStartValue(int newValue)
{
    startValue = newValue;
    resetSeries();
}

void NumberSeries::setFunction(int(*func)(int))
{
   this-> func = func;
   resetSeries();
}