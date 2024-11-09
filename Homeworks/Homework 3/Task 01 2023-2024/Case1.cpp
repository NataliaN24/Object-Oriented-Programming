#include "Case1.h"

Case1::Case1(int32_t* undefinedInputs, uint16_t N) :BaseCase(undefinedInputs, N)
{
}

MyPair<bool, int32_t> Case1::operator()(int32_t x) const
{
    for (uint16_t i = 0; i < N; ++i) 
    {
        if (inputs[i] == x)
        {
            return MyPair<bool, int32_t>(false, 0);
        }
    }
    return MyPair<bool, int32_t>(true, x);
}