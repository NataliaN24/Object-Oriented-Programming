#pragma once
#include"BaseCase.h"

class Case1 :public BaseCase
{
public:

    Case1(int32_t* undefinedArgs, uint16_t N);
    MyPair<bool, int32_t> operator()(int32_t x) const override;

};