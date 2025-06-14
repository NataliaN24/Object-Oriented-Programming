#include "MPeak.h"

MPeak::MPeak(const char* name, double h, double number):Peak(name,h)
{
    setNumber(number);
}

MPeak::MPeak():number(0.0)
{
}

void MPeak::setNumber(double newNum)
{
    this->number = newNum;
}

double MPeak::getNumber() const
{
    return number;
}

void MPeak::printPeakName() const
{
    std::cout << "Mpeak";
}

Peak* MPeak::clone() const
{
    return new MPeak(*this);
}

bool MPeak::twoPeaksNear(const Peak* other) const
{
    return other->nearMpeak(this);
}

bool MPeak::nearMpeak(const MPeak* mpeak) const
{
    std::cout << "near mpeak";
    return true;
}

bool MPeak::nearTPeak(const TPeak* tpeak) const
{
    std::cout << "near tpeak";
    return true;
}
