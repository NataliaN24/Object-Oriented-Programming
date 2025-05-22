#include "TriangleParcel.h"

TriangleParcel::TriangleParcel(double a, double b, double c):a(a),b(b),c(c)
{
}

double TriangleParcel::perimeter() const
{
    return a + b + c;
}

double TriangleParcel::area() const
{
    double halfPerimeter = perimeter() / 2;
    return sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
}

Parcel* TriangleParcel::clone() const
{
    return new TriangleParcel(*this);
}
