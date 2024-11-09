#include "Case0.h"

Case0::Case0(int32_t* inputs, int32_t* outputs, uint16_t N) :BaseCase(inputs, N), outputs(outputs)
{
}

MyPair<bool, int32_t> Case0::operator()(int32_t x) const
{
    for (uint16_t i = 0; i < N; ++i)
    {
        if (inputs[i] == x)
        {
            return MyPair<bool, int32_t>(true, outputs[i]);
        }
    }
    return MyPair<bool, int32_t>(false, 0);
}

void Case0::copyFrom(const Case0& other)
{
    outputs = new int32_t[other.N];

    for (uint16_t i = 0; i < other.N; ++i)
    {
        outputs[i] = other.outputs[i];
    }
}

void Case0::moveFrom(Case0&& other)noexcept
{

    outputs = other.outputs;

    other.outputs = nullptr;

}

void Case0::free()
{
    delete[]outputs;
}

Case0::Case0():outputs(nullptr)
{
}

Case0::Case0(const Case0& other) :BaseCase(other)
{
    copyFrom(other);
}

Case0::Case0(Case0&& other) noexcept :BaseCase(other)
{
    moveFrom(std::move(other));
}

Case0& Case0::operator=(const Case0& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
        BaseCase::operator=(other);
    }
    return *this;
}

Case0& Case0::operator=(Case0&& other)noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
        BaseCase::operator=(std::move(other));
    }
    return *this;
}

Case0::~Case0()
{
    free();
}