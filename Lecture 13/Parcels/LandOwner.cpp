#include "LandOwner.h"

void LandOwner::copyFrom(const LandOwner& other)
{
    count = other.count;
    capacity = other.capacity;
    parcels = new Parcel * [capacity];
    for (int i = 0; i < count; i++)
    {
        parcels[i] = other.parcels[i]->clone();
    }
}

void LandOwner::free()
{
    for (int i = 0; i < count; i++)
    {
        delete parcels[i];
    }
    if (parcels)
    {
        delete[]parcels;
    }
}

void LandOwner::resize(int newCap)
{
    Parcel** copy = new Parcel * [newCap];
    for (int i = 0; i < count; i++)
    {
        copy[i] = parcels[i];
    }
    delete[]parcels;
    capacity = newCap;
    parcels = copy;
}

LandOwner::LandOwner()
{
    count = 0;
    capacity = 8;
    parcels = new Parcel * [capacity];
}

LandOwner::LandOwner(const LandOwner& other)
{
    copyFrom(other);
}

LandOwner& LandOwner::operator=(const LandOwner& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

LandOwner::~LandOwner()
{
    free();
}

void LandOwner::addParcel(const Parcel& other)
{
    if (count == capacity)
    {
        resize(capacity * 2);
    }
    parcels[count++] = other.clone();
}

void LandOwner::addParcel( const char*str)
{
    if (count == capacity)
    {
        resize(capacity * 2);
    }
    Parcel* newParcel = factory(str);
    if (newParcel)
    {
        addParcel(*newParcel);
        delete newParcel;
    }
}

void LandOwner::removeParcel(int index)
{
    if (index < 0 || index >= count) return;
    delete parcels[index];
    for (int i = index; i < count; i++)
    {
        parcels[i] = parcels[i + 1];
    }
    count--;
}

double LandOwner::getTotalPerimeter() const
{
    double totalPer = 0;
    for (int i = 0; i < count-1; i++)
    {
        totalPer += parcels[i]->perimeter();
    }
    return totalPer;
}

double LandOwner::getTotalArea() const
{
    double totalArea = 0;
    for (int i = 0; i < count; i++)
    {
        totalArea += parcels[i]->area();
    }
    return totalArea;
}
