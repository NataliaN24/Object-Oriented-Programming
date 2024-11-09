#include <iostream>
#include <stdexcept>
#pragma once

namespace CONSTANTS
{
    constexpr int16_t MAX_16_VALUE = 32767;
    constexpr int16_t MIN_16_VALUE = -32767;
    constexpr int MAX_SIZE = MAX_16_VALUE - MIN_16_VALUE;
}
namespace NUMBERS
{
    constexpr int ONE = 1;
    constexpr int ZERO = 0;
}

class ModifiableIntegersFunction 
{
    int16_t(*func)(int16_t);
    int16_t* specificOutput;
    bool* excludingPoints;

    void copyFrom(const ModifiableIntegersFunction& other);
    void moveFrom(ModifiableIntegersFunction&& other)noexcept;
    void free();
   
public:

    ModifiableIntegersFunction();
    ModifiableIntegersFunction(const ModifiableIntegersFunction& other);
    ModifiableIntegersFunction(ModifiableIntegersFunction&& other)noexcept;
    ModifiableIntegersFunction& operator=(const ModifiableIntegersFunction& other);
    ModifiableIntegersFunction& operator=(ModifiableIntegersFunction&& other)noexcept;
    ~ModifiableIntegersFunction();

    ModifiableIntegersFunction(int16_t(*function)(int16_t));

    void setOutputForSpecificInput(int16_t input, int16_t output);
    void exclusion(int16_t input);

    int16_t operator()(int16_t input)const ;

    ModifiableIntegersFunction& operator+=(const ModifiableIntegersFunction& other);
    ModifiableIntegersFunction& operator-=(const ModifiableIntegersFunction& other);
    ModifiableIntegersFunction& operator*=(const ModifiableIntegersFunction& other);
    ModifiableIntegersFunction operator^(int k) ;


    bool operator<(const ModifiableIntegersFunction& other)const ;
    bool  operator>(const ModifiableIntegersFunction& other) const;
    bool operator<=(const ModifiableIntegersFunction& other) const;
    bool operator>=(const ModifiableIntegersFunction& other) const;
    bool operator==(const ModifiableIntegersFunction& other) const;
    bool operator!=(const ModifiableIntegersFunction& other) const;

    bool isInjective() const;
    bool isSurjective() const;
    bool isBijective() const;

    void plot(double x1, double x2, double y1, double y2) const;
};

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
ModifiableIntegersFunction operator*(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
bool areGraphsParallel(const ModifiableIntegersFunction& f1, const ModifiableIntegersFunction& f2);