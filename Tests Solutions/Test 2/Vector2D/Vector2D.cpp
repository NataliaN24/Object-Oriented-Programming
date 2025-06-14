#include "Vector2D.h"

Vector2D::Vector2D():x(0.0),y(0.0)
{
}

Vector2D::Vector2D(double _x, double _y):x(_x),y(_y)
{
}

double Vector2D::getX() const
{
    return x;
}

double Vector2D::getY() const
{
    return y;
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2D operator*( double number, const  Vector2D& vector)
{
    return Vector2D(vector.x * number, vector.y * number);
}


Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
    Vector2D result(lhs);
    result += rhs;
    return result;
}
bool operator==(const Vector2D& lhs, const Vector2D& rhs) {
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}
bool operator!=(const Vector2D& lhs, const Vector2D& rhs) {
    return !(lhs == rhs);
}
double operator^(const Vector2D& lhs, const Vector2D& rhs) {
    return lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY();
}

Vector2D operator*(const Vector2D& lhs, double n) {
    Vector2D result(lhs);
    return n* result;
    
}