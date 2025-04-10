#pragma once
#include "HelperUtils.h"

class Time 
{
private:

    unsigned hours=0;
    unsigned minutes=0;
    unsigned seconds=0;

public:

    Time() = default;
    Time(unsigned h, unsigned m, unsigned s);

    unsigned getHours() const;
    unsigned getMinutes() const;
    unsigned getSeconds() const;

    void setHours(unsigned h);
    void setMinutes(unsigned m);
    void setSeconds(unsigned s);

    unsigned toSeconds() const;

    void printTime() const;
};