#pragma once
#include"BaseCase.h"
#include<iostream>


class Case0 :public BaseCase
{
public:

    Case0(int32_t* args, int32_t* results, uint16_t N);
    MyPair<bool, int32_t> operator()(int32_t x) const override;

private:

    int32_t* outputs;

    void copyFrom(const Case0& other);
    void moveFrom(Case0&& other)noexcept;
    void free();

public:
    Case0();
    Case0(const Case0& other);
    Case0(Case0&& other)noexcept;
    Case0& operator=(const Case0& other);
    Case0& operator=(Case0&& other)noexcept;
    ~Case0();
};