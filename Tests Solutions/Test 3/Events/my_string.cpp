#include "my_string.h"

void my_string::copyFrom(const my_string& other)
{
    str = new char[strlen(other.str) + 1];
    std:: strcpy(str, other.str);
}

void my_string::free()
{
    delete[]str;
}

my_string::my_string()
{
    str = new char[1];
    str[0] = '\0';
}

my_string::my_string(const char* str)
{
    if (str == nullptr)
    {
        this->str = new char[1];
       this-> str[0] = '\0';
    }
    if (this->str)
    {
        delete[]this->str;
    }
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
}

my_string::my_string(const my_string& other)
{
    copyFrom(other);
}

my_string& my_string::operator=(const my_string& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
   }
    return *this;
}

my_string::~my_string()
{
    free();
}

const char* my_string::c_str() const
{
    return str;
}

size_t my_string::length() const
{
    return strlen(str);
}

const char &my_string::operator[](size_t index) const
{
    return str[index];
}

char& my_string::operator[](size_t index)
{
    return str[index];
}

std::ostream& operator<<(std::ostream& os, const my_string& obj) {
    os << obj.c_str();
    return os;
 }