#include "Utils.h"
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

char convertIntoAsciiCode(const char* ptr, int& count)
{
    int asciNumber = 0;

    const char* startNumber = ptr;

    while (*startNumber && isDigit(*startNumber))
    {
        asciNumber = asciNumber * 10 + (*startNumber - '0');
        ++startNumber;
        count++;
    }

    if (asciNumber >= 0 && asciNumber <= 127)
    {
        return char(asciNumber);
    }

    else
    {
        return '?';
    }

    return *ptr;
}