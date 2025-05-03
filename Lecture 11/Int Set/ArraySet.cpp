#include "ArraySet.h"

ArraySet::ArraySet(int n):capacity(n)
{
    numbers = new int[capacity];
    count = 0;
}

bool ArraySet::member(int x) const
{
    for (int i = 0; i < count; i++)
    {
        if (numbers[i] == x)
        {
            return true;
        }
    }
    return false;
}

int ArraySet::getIndex(int x) const
{
    for (int i = 0; i < count; i++)
    {
        if (numbers[i] == x)
        {
            return i;
        }
    }
    return -1;

}

bool ArraySet::insert(int x) 
{
    if (count >= capacity|| member(x))
    {
        return false;
    }
    numbers[count++] = x;
    return true;
}

bool ArraySet::remove(int x) 
{
    if (!member(x))
    {
        return false;
    }
 
    int index = getIndex(x);
    std::swap(numbers[count - 1], numbers[index]);
    count--;
    return true;
}
