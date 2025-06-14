#include "TinyMultiset.h"

void TinyMultiset::add(int num)
{
    if (num < 0 || num>31)
    {
        return;
    }
    if (count[num] < 3)
    {
        count[num]++;
    }
}

void TinyMultiset::remove(int num)
{
    if (num < 0 || num>31)
    {
        return;
    }
    if (count[num] > 0)
    {
        count[num]--;
    }

}

int TinyMultiset::operator()(int num) const
{
    if (num < 0 || num>31)
    {
        return 0;
    }
    return count[num];
}
