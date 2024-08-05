#include "NVector.h"

void NVector::copyFrom(const NVector& other)
{
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

void NVector::free()
{
    delete[]data;
    data = nullptr;
    size = 0;
}

NVector::NVector(size_t size):size(size)
{
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = 0;
    }
}

NVector::NVector(const NVector& other)
{
    copyFrom(other);
}

NVector& NVector::operator=(const NVector& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

NVector::~NVector()
{
    free();
}

NVector& NVector::operator+=(const NVector& other)
{
    if (size != other.size)
    {
        throw"They should have the same size";
    }
    for (int i = 0; i < size; i++)
    {
        data[i] += other.data[i];
    }
    return *this;
}

NVector& NVector::operator-=(const NVector& other)
{
    if (size != other.size)
    {
        throw"They should have the same size";
    }
    for (int i = 0; i < size; i++)
    {
        data[i] -= other.data[i];
    }
    return *this;
}

NVector& NVector::operator*=(size_t scalar)
{
    for (int i = 0; i < size; i++)
    {
        data[i] *= scalar;
    }
    return *this;
}

int& NVector::operator[](size_t index)
{
    if (index >= size) {
        throw std::out_of_range("error");
    }
    return data[index];
}

int NVector::operator[](size_t index) const
{
    if (index >= size) {
        throw std::out_of_range("error");
    }
    return data[index];
}

size_t NVector::operator~() const
{
    return size;
}

std::ostream& operator<<(std::ostream& os, const NVector& other)
{
    os << "[";
    for (int i = 0; i < other.size; i++)
    {
        os << other.data[i] << " ";
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, NVector& other)
{
    for (int i = 0; i < other.size; ++i)
    {
        is >> other.data[i];
    }
    return is;
}

NVector operator+(const NVector& lhs, const NVector& rhs)
{
    NVector result(lhs);
    result += rhs;
    return result;

}

NVector operator-(const NVector& lhs, const NVector& rhs)
{
    NVector result(lhs);
    result -= rhs;
    return result;
}

NVector operator*(const NVector& lhs, size_t scalar)
{
    NVector result(lhs);
    result *= scalar;
    return result;
}

NVector operator*(size_t scalar, const NVector& lhs)
{
    return lhs * scalar;
}

bool operator||(const NVector& lhs, const NVector& rhs)
{
    if (~lhs != ~rhs)
    {
        throw "The vectors should have the same size!";
    }
    double ratio = 0.0;
    bool ratioSet = false;

    for (int i = 0; i < ~lhs; i++)
    {
        if (lhs[i] == 0 && rhs[i] == 0)
        {
            continue;
        }
        if (lhs[i] == 0 || rhs[i] == 0)
        {
            return false;
        }
        double currentRatio = lhs[i] / rhs[i];
        if (!ratioSet)
        {
            ratio = currentRatio;
            ratioSet = true;
        }
        else if (std::abs(ratio - currentRatio) > 1e-6)
        {
            return false;
        }
    }
    return true;

}

//scalar product
size_t operator%(const NVector& lhs, const NVector& rhs)
{
    if (~lhs != ~rhs) {
        throw "The vectors should have the same size!";
    }
    size_t res = 0;
    for (int i = 0; i < ~lhs;i++)
    {
        res += lhs[i] * rhs[i];
    }
    return res;
}

bool operator|=(const NVector& lhs, const NVector& rhs)
{
    return lhs % rhs == 0;
}
