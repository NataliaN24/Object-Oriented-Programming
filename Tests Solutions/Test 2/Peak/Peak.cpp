#include "Peak.h"

void Peak::copyFrom(const Peak& other)
{
    nameMountain = new char[strlen(other.nameMountain) + 1];
    strcpy(this->nameMountain, other.nameMountain);
    height = other.height;
}

void Peak::free()
{
    delete[]nameMountain;
    height = 0.0;

}

Peak::Peak():height(0.0)
{
    nameMountain = new char[1];
    nameMountain[0] = '\0';
}

Peak::Peak(const char* name, double height)
{
    setName(name);
    setHeight(height);
}

Peak::Peak(const Peak& other)
{
    copyFrom(other);
}

Peak& Peak::operator=(const Peak& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Peak::~Peak()
{
    free();
}

const char* Peak::getName() const
{
    return nameMountain;
}

double Peak::getHeight() const
{
    return height;
}

void Peak::setName(const char* newName)
{
    if (this->nameMountain)
    {
        delete[]nameMountain;
    }
    nameMountain = new char[strlen(newName) + 1];
    strcpy(this->nameMountain, newName);
}

void Peak::setHeight(double h)
{
    height = h;
}
