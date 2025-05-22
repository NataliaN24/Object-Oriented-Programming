#include "CircleParcel.h"

CircleParcel::CircleParcel(double rad):radius(rad)
{
}

double CircleParcel::perimeter() const
{
    return 2 * radius * pi;
}

double CircleParcel::area() const
{
    return pi * radius * radius;
}

Parcel* CircleParcel::clone() const
{
    return new CircleParcel(*this);
}
