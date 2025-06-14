#include "Polynom.h"

void Polynom::copyFrom(const Polynom& other)
{
    count = other.count;
    coefficients = new size_t[count];
    for (size_t i = 0; i < count; i++)
    {
        coefficients[i] = other.coefficients[i];
    }
}

void Polynom::free()
{
    delete[]coefficients;
    count = 0;
}

void Polynom::resize(size_t maxCount)
{
    size_t* newArr = new size_t[maxCount]{ 0 };

    // Copy old values to the end (align powers!)
    int offset = maxCount - count;
    for (int i = 0; i < count; i++)
    {
        newArr[i + offset] = coefficients[i];
    }

    delete[] coefficients;
    coefficients = newArr;
    count = maxCount;
}

Polynom::Polynom():count(0)
{
    coefficients = new size_t[count];
}

Polynom::Polynom(size_t* arr, size_t n)
{
    count = n;
    coefficients = new size_t[count];
    for (int i = 0; i < count; i++)
    {
        coefficients[i] = arr[i];
    }
}

Polynom::Polynom(const Polynom& other)
{
    copyFrom(other);
}

Polynom& Polynom::operator=(const Polynom& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Polynom::~Polynom()
{
    free();
}

Polynom::Polynom(size_t n)
{
    count = n;
    coefficients = new size_t[count];
    for (size_t i = 0; i < count; i++)
    {
        coefficients[i] = 1;
    }
}
int getCharCount(std::ifstream& ifs)
{
    if (!ifs.is_open())
    {
        throw ("Error opening the file!");
    }
    int count = 0;
    bool lastNewLine = false;

    while (!ifs.eof())
    {
        char current = ifs.get();
        if (current == NEW_LINE)
        {
            count++;
            lastNewLine = false;
        }
        if (ifs.eof())
        {
            lastNewLine = true;
        }
      
        
    }
    if (lastNewLine)
    {
        count++;
    }
    ifs.clear();
    ifs.seekg(0);

    return count;

}
void Polynom::load(std::ifstream& ifs)
{
    if (!ifs.is_open())
    {
        throw ("Error opening the file!");
    }
    count = getCharCount(ifs);
    delete[]coefficients;
    coefficients = new size_t[count];
    for (int i = 0; i < count; i++)
    {
        ifs >> coefficients[i];
    }
}

void Polynom::print() const
{
    for (int i = 0; i < count; i++)
    {
        std::cout << coefficients[i];
        int power = count - i-1 ;
        if (power > 0)
            std::cout << "x^" << power;
        if (i < count - 1)
            std::cout << " + ";
    }
    std::cout << std::endl;
}

void Polynom::add(const Polynom& other)
{
    int maxCount = (this->count > other.count) ? this->count : other.count;
    int minCount = (this->count < other.count) ? this->count : other.count;

    if (count < maxCount)
    {
        resize(maxCount);
    }

    int offset = maxCount - other.count;
    for (int i = 0; i < other.count; i++)
    {
        coefficients[i + offset] += other.coefficients[i];
    }
}

