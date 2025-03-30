#include "Path.h"

void Path::copyFrom(const Path& other)
{
    towns = new Town[other.capacity];
    for (int i = 0; i < other.count; i++)
    {
        towns[i] = other.towns[i];
    }
    count = other.count;
    capacity = other.capacity;
}

void Path::free()
{
    delete[]towns;
}

void Path::resize(unsigned int newCap)
{
    capacity = newCap;
    Town* copy = new Town[capacity];
    for (int i = 0; i < count; i++)
    {
        copy[i] = towns[i];
    }
    delete[]towns;
    towns = copy;
}

Path::Path()
{
    capacity = 10;
    towns = new Town[capacity];
    count = 0;
   
}

Path::Path(const Path& other)
{
    copyFrom(other);
}

Path& Path::operator=(const Path& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Path::~Path()
{
    free();
}


int Path::getIndexOfTown(const Town& other) const
{
        int index = 0;
        while (index < count && towns[index].getID() < other.getID())
        {
            index++;
       }
        return index;
}

void Path::addTown(const Town& newTown)
{
    if (count >= capacity) {
        resize(capacity * 2);
    }
    if (existsTown(newTown.getID()))
    {
        std::cout << "Town already exists";
        return;
    }
    int indexToAddTown = getIndexOfTown(newTown);
    for (int i = count; i > indexToAddTown; i--)
    {
        towns[i] = towns[i - 1];
    }
    towns[indexToAddTown] = newTown;
    count++;
}

void Path::removeTown(const Town& newTown)
{
    if (!existsTown(newTown.getID()))
    {
        std::cout << "Town doesn't exist";
        return;
    }
    int indexOfTown = getIndexOfTown(newTown);
    for (int i = indexOfTown; i < count-1; i++)
    {
        towns[i] = towns[i + 1];
    }
    count--;
}

bool Path::isCityInPath(const Town& town) const
{
    for (int i = 0; i < count; i++) {
        if (towns[i].getID() == town.getID())
        {
            return true;
        }
    }
    return false;
}

Path Path::unionPaths(const Path& rhs)
{
    Path result;
    for (int i = 0; i < count; i++)
    {
        result.addTown(towns[i]);
    }
    for (int i = 0; i < rhs.count; i++)
    {
        if (!result.isCityInPath(rhs.towns[i]))
        {
            result.addTown(rhs.towns[i]);
        }
    }
    return result;

}

Path Path::intersectionPaths(const Path& rhs)
{
    Path result;
    for (int i = 0; i < count; i++)
    {
        if (rhs.isCityInPath(towns[i]))
        {
            result.addTown(towns[i]);
       }
    }
    return result;
}

bool Path::doHaveMutualTowns(const Path& p1, const Path& p2) const
{
    for (int i = 0; i < p1.count; i++)
    {
        for (int j = 0; j < p2.count; j++)
        {
            if (p1.towns[i].getID() == p2.towns[j].getID())
            {
                return true;
            }
        }
    }
    return false;
}

bool Path::areThereAnyTowns() const
{
    return count > 0;
}

bool Path::existsTown(unsigned int id) const
{
    for (int i = 0; i < count; i++)
    {
        if (towns[i].getID() == id)
        {
            return true;
        }
    }
    return false;
}

unsigned int Path::howManyTowns() const
{
    return count;
}

void Path::print() const
{
    for (int i = 0; i < count; i++)
    {
        std::cout << towns[i].getID() << " ";
    }
}
