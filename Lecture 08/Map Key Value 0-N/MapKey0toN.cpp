#include "MapKey0toN.h"

MapKey0toN::MapKey0toN(unsigned nullValue)
{
    for (int i = 0; i < N; i++)
    {
        values[i] = nullValue;
    }
    this->nullValue = nullValue;
}

void MapKey0toN::add(unsigned key, unsigned value)
{
    if (value == nullValue)
    {
        return;
    }
    values[key] = value;
}

bool MapKey0toN::contains(unsigned key) const
{
    return values[key] != nullValue;
}

unsigned MapKey0toN::getValue(unsigned key) const
{
    if (!contains(key))
    {
        throw"Error";
    }
    return values[key];
}
