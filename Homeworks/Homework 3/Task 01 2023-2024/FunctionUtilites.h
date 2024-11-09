#pragma once
#include "PartialFunction.h"
#include "PartialFunctionLoader.h"
#include <iostream>

class FunctionUtilities 
{
public:

    FunctionUtilities(PartialFunction* func);

    void mode1();
    void mode2();

private:

    PartialFunction* func;

    void copyFrom(const FunctionUtilities& other);
    void moveFrom(FunctionUtilities&& other)noexcept;
    void free();

public:
    FunctionUtilities();
    FunctionUtilities(const FunctionUtilities& other);
    FunctionUtilities(FunctionUtilities&& other)noexcept;
    FunctionUtilities& operator=(const FunctionUtilities& other);
    FunctionUtilities& operator=(FunctionUtilities&& other)noexcept;
    ~FunctionUtilities();
};