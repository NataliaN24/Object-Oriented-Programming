#pragma once
#include"BaseCase.h"

class Case2 :public BaseCase
{
public:

    Case2(int32_t* specificArgs, uint16_t N);
    MyPair<bool, int32_t> operator()(int32_t x) const override;
};