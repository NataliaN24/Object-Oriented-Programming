#include "ImmutableString.h"

StringPool ImmutableString::pool;

void ImmutableString::copyFrom(const ImmutableString& other)
{
    data = pool.getAllocatedString(other.data);
    length = other.length;
}

void ImmutableString::free()
{
    pool.releaseString(data);
    data = nullptr;
}

ImmutableString::ImmutableString(const char* data)
{
   this->data = pool.getAllocatedString(data);
   length = strlen(data);
}

ImmutableString::ImmutableString(const ImmutableString& other)
{
    copyFrom(other);
}

ImmutableString::~ImmutableString()
{
    free();
}

size_t ImmutableString::getLength() const
{
    return length;
}

char ImmutableString::operator[](size_t index) const
{
    return data[index];
}

const char* ImmutableString::c_str() const
{
    return data;
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& str)
{
    return os << str.c_str();
}

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}