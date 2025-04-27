#include "Registration.h"

bool isLetter(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}
bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}
bool isValidForMinLength(const char* number)
{

        for (int i = 1; i <1+ digits; i++)
        {
            if (!isDigit(number[i]))
            {
                return false;
            }
        }
        for (int i = 1+digits; i < minSize; i++)
        {
            if (!isLetter(number[i]))
            {
                return false;
            }
        }
    return true;
}
bool isValidForMaxLength(const char* number)
{

        for (int i = 2; i < 2+digits; i++)
        {
            if (!isDigit(number[i]))
            {
                return false;
            }
        }
        for (int i = digits + 2; i < maxSize; i++)
        {
            if (!isLetter(number[i]))
            {
                return false;
            }
        }
    return true;
}

bool isValid(const char* number)
{
    if (number == nullptr)
    {
        return false;
    }
    size_t len = strlen(number);
    if (len != minSize && len != maxSize)
    {
        return false;
    }
    if (!isLetter(number[0]))
    {
        return false;
    }
    if (len == minSize) 
    {
        if (!isLetter(number[1]))
        {
            return isValidForMinLength(number);
        }
        else
        {
            return false;
        }
      
    }
    if (len == maxSize ) {
        if (isLetter(number[1]))
        {
            return isValidForMaxLength(number);
        }
        else
        {
            return false;
        } 
    }
    return false;

}
Registration::Registration(const char* str)
{
    if (isValid(str))
    {
        strcpy(regNumber, str);
    }
    else
    {
        throw std::invalid_argument("Invalid registration number!");
    }
}

bool Registration::operator==(const Registration& other)
{
    return strcmp(regNumber, other.regNumber) == 0;
}

bool Registration::operator!=(const Registration& other)
{
    return strcmp(regNumber, other.regNumber) != 0;
}

const char* Registration::getRegNumber() const
{
    return regNumber;
}

