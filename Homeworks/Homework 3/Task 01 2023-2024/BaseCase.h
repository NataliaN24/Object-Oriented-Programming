#pragma once
#include"MyPair.hpp"

class BaseCase
{
public:

    BaseCase(int32_t* inputs, uint16_t N);
    virtual MyPair<bool, int32_t> operator()(int32_t x) const = 0;

    BaseCase();
    BaseCase(const BaseCase& other);
    BaseCase(BaseCase&& other)noexcept;
    BaseCase& operator=(const BaseCase& other);
    BaseCase& operator=(BaseCase&& other)noexcept;
    virtual ~BaseCase();

protected:

    int32_t* inputs;
    uint16_t N;

    void copyFrom(const BaseCase& other);
    void moveFrom(BaseCase&& other)noexcept;
    void free();
};