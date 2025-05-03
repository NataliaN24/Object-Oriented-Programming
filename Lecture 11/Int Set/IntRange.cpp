#include "IntRange.h"


IntRange::IntRange():IntRange(0,0)
{
}

IntRange::IntRange(int start, int end):start(start),end(end)
{
    count = end - start + 1;
    numbers = new int[count];
    for (int i = 0; i < count; i++)
    {
        numbers[i] = start+i ;
    }
}

bool IntRange::member(int x) const
{
    return x >= start && x <= end;
}

int IntRange::get(int i) const
{
    if (i < 0 || i >= count) {
        throw std::out_of_range("Index out of range");
    }
    return numbers[i];
}

bool IntRange::isSubsetOf(const IntSet& other) const {
    for (int i = 0; i < count; i++) {
        if (!other.member(numbers[i])) {
            return false;
        }
    }
    return true;
}


bool IntRange::intersects(const IntSet& other) const {
    for (int i = 0; i < count; i++) {
        if (other.member(numbers[i])) {
            return true;
        }
    }
    return false;
}
