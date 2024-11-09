#include "Case2.h"

Case2::Case2(int32_t* specificArgs, uint16_t N) :BaseCase(specificArgs, N)
{
}

MyPair<bool, int32_t> Case2::operator()(int32_t x) const
{
    for (uint16_t i = 0; i < N; ++i)
    {
        if (inputs[i] == x)
        {
            return MyPair<bool, int32_t>(true, 1);
        }
    }
    return MyPair<bool, int32_t>(true, 0);
}