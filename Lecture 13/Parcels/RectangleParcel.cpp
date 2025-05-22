#include "RectangleParcel.h"

RectangleParcel::RectangleParcel(double a, double b):a(a),b(b)
{
}

double RectangleParcel::perimeter() const
{
    return 2 * a + 2 * b;
}

double RectangleParcel::area() const
{
    return a * b;
}

Parcel* RectangleParcel::clone() const
{
    return new RectangleParcel(*this);
}
