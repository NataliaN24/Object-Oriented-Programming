#include "Shape.h"
#include <assert.h>

const  Shape ::Point&Shape:: getPointAtIndex(size_t index) const
{
    if (index >= count)
    {
        throw std::exception("Invalid point index!");
    }
    return points[index];
}

void Shape::copyFrom(const Shape& other)
{
    count = other.count;
    points = new Point[count];
    for (int i = 0; i < count; ++i)
    {
        points[i] = other.points[i];
    }
}

void Shape::moveFrom(Shape&& other)
{
    points = other.points;
    count = other.count;
    other.points = nullptr;
    other.count = 0;
}

void Shape::free()
{
    delete[]points;
    points = nullptr;
    count = 0;
}

Shape::Shape(size_t pointsCount):count(pointsCount)
{
    if (pointsCount > 0)
    {
        points = new Point[pointsCount];
    }
}

Shape::Shape(const Shape& other)
{
    copyFrom(other);
}

Shape::Shape(Shape&& other) noexcept
{
    moveFrom(std::move(other));
}

Shape& Shape::operator=(const Shape& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Shape& Shape::operator=(Shape&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Shape::~Shape()
{
    free();
}

void Shape::setPoint(size_t index, int x, int y)
{
    if (index >= count || points == nullptr)
    {
        throw std::exception("Invalid point index or uninitialized points array!");
    }
    points[index] = Point(x, y);
}

double Shape::getPer() const
{
    assert(count >= 3);
    double perimetre = 0;
    for (int i = 0; i < count-1; ++i)
    {
        perimetre += points[i].getDist(points[i + 1]);
    }
    return perimetre + points[count - 1].getDist(points[0]);
}
