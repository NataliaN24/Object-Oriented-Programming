#include "Collection.h"

void Collection::copyFrom(const Collection& other)
{
    peaks = new Peak * [size];
    for (int i = 0; i < size; i++)
    {
        peaks[i] = other.peaks[i];
    }
}

void Collection::free()
{
    for (int i = 0; i < size; i++)
    {
        delete peaks[i];
    }
    delete[]peaks;
}

Collection::Collection():size(4)
{
    peaks = new Peak * [size];

}

Collection::Collection(const Collection& other)
{
    copyFrom(other);
}

Collection& Collection::operator=(const Collection& other)
{

    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Collection::~Collection()
{
    free();
}

void Collection::resize()
{
    capacity *= 2;
    Peak** newPeaks = new Peak * [capacity];
    for (size_t i = 0; i < size; i++)
    {
        newPeaks[i] = peaks[i];
    }
    delete[] peaks;
    peaks = newPeaks;
}


void Collection::addPeak(const Peak* obj)
{
    if (size >= capacity)
        resize();
    peaks[size++] = obj->clone();
}

void Collection::addPeak(const Peak& obj)
{
    
    addPeak(&obj);
}

void Collection::removePeak(const Peak& obj)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(peaks[i]->getName(),obj.getName() )== 0) {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        delete peaks[index];
        size--;

    }
}

Peak* Collection::getPeakAt(size_t index)
{
    if (index > size)
    {
      throw "error";
    }
    return peaks[index];
    
}

void Collection::printPeaks() const
{
    for (int i = 0; i < size; i++)
    {
        peaks[i]->printPeakName();
    }
}
