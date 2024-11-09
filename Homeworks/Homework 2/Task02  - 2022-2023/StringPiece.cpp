#include "StringPiece.h"
#include<iostream>
#include<cstring>

StringPiece::StringPiece(const char* str) :size(strlen(str)) 
{
    size_t len = std::min(size, (size_t)15);
    strncpy(value, str, len);
    value[len] = '\0';
}

const char* StringPiece::getValue() const 
{
    return value;
}

size_t StringPiece::getSize()const
{
    return size;
}

void StringPiece::setValue(const char* str)
{
    size_t len = std::min(size, (size_t)15);
    strncpy(value, str, len);
    value[len] = '\0';
    size = len;
}

void StringPiece::removeFirst(int k)
{
    if (k <= 0) 
    {
        return;
    }
    else if (k >= size)
    {
        value[0] = '\0';
        size = 0;
    }
    else 
    {
        for (int i = k; i <= size; i++) 
        {
            value[i - k] = value[i];
        }
        size -= k;
    }
    value[size] = '\0';
}

void StringPiece::removeLast(int k) 
{
    if (k <= 0) {
        return;
    }
    else if (k >= size)
    {
        value[0] = '\0';
        size = 0;
        return;
    }
    else 
    {
        size -= k;
        value[size] = '\0';
    }
}

void StringPiece::changeSymbol(char symbol,int index)
{
    if (index > size||index<0) {
        throw std::out_of_range("Index is out of range!");
    }
    else {
        value[index] = symbol;
    }
}

void StringPiece::print()const
{
    for (int i = 0; i < strlen(value); i++)
    {
        std::cout << value[i];
    }
    std::cout << std::endl;
}

StringPiece& StringPiece:: operator<<( const char* str)
{
    if (!str || std::strlen(str) == 0)
    {
        return*this;
    }
    size_t len = strlen(str);

    if (size + len > 15)
    {
        len = 15 - size;
    }
    
    for (int i = size - 1; i >= 0; i--)
    {
        value[i + len] = value[i];
    }
    for (int i = 0; i < len; i++)
    {
        value[i] = str[i];
    }
    size += len;
    return *this;
}

StringPiece& StringPiece::operator>>(const char* str)
{
  
    if (!str || std::strlen(str) == 0)
    {
        return*this;
    }
    size_t len = strlen(str);

    if (size + len > 15)
    {
        len = 15 - size;
    }

    for (size_t i = 0; i < len; ++i)
    {
        value[size + i] = str[i];
    }
    value[size + len] = '\0';
    size += len;
    return *this;
}

void swap(char& a, char & b) 
{
    char temp = a;
    a = b;
    b = temp;
}

StringPiece& StringPiece::operator<<(int num)
{
    if (num == 0) 
    {
        return *this << "0";
    }

    char buffer[16];
    int i = 0;
    bool is_negative = false;

    if (num < 0)
    {
        is_negative = true;
        num = -num;
    }

    while (num != 0) 
    {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    }

    if (is_negative) 
    {
        buffer[i++] = '-';
    }

    buffer[i] = '\0';

    int j = i - 1;
    i = 0;

    while (i < j) 
    {
        swap(buffer[i], buffer[j]);
        ++i;
        --j;
    }
    return *this << buffer;
}

StringPiece& StringPiece:: operator>>(int num)
{
    if (num == 0)
    {
        return *this >> "0";
    }

    char buffer[16];
    int i = 0;
    bool is_negative = false;

    if (num < 0) 
    {
        is_negative = true;
        num = -num;
    }

    while (num != 0) 
    {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    }

    if (is_negative)
    {
        buffer[i++] = '-';
    }

    buffer[i] = '\0';

    int j = i - 1;
    i = 0;
    while (i < j) 
    {
        swap(buffer[i], buffer[j]);
        ++i;
        --j;
    }
    return *this >> buffer;
}