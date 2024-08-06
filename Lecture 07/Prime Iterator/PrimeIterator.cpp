#include "PrimeIterator.h"
#include <cmath>

namespace 
{
    bool isPrime(unsigned int number) 
    {
        if (number == 2)
        {
            return true;
        }

        if (number == 1 || number % 2 == 0)
        {
            return false;
        }

        double sqrtN = sqrt(number);
        for (int i = 3; i <= sqrtN; i += 2)
        {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
}

PrimeIterator& PrimeIterator::goToNext()
{
    while (!isPrime(++value)) {}
    return *this;
}

PrimeIterator& PrimeIterator::goToPrev()
{
    if (value != 2)
    {
        while(!isPrime(--value)){}
    }
    return *this;
}

PrimeIterator::PrimeIterator(size_t value)
{
    setValue(value);
}

PrimeIterator::PrimeIterator():PrimeIterator(2)
{
}

size_t PrimeIterator::getValue() const
{
    return value;
}

void PrimeIterator::setValue(size_t value)
{
    this->value = isPrime(value) ? value : 2;
}

PrimeIterator& PrimeIterator::operator++()
{
    return goToNext();
}

PrimeIterator PrimeIterator::operator++(int)
{
    PrimeIterator copy(*this);
    goToNext();
    return copy;
}

PrimeIterator& PrimeIterator::operator--()
{
    return goToPrev();
}

PrimeIterator PrimeIterator::operator--(int)
{
    PrimeIterator copy(*this);
    goToPrev();
    return copy;
}

unsigned PrimeIterator::operator*() const
{
    return value;
}

bool operator==(const PrimeIterator& lhs, const PrimeIterator& rhs)
{
    return lhs.getValue() == rhs.getValue();
}

bool operator!=(const PrimeIterator& lhs, const PrimeIterator& rhs)
{
    return !(lhs == rhs);
}
