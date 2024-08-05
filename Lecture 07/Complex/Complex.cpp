#include "Complex.h"

Complex::Complex()
{
    real = 0;
    im = 0;
}

Complex::Complex(double real, double im):real(real),im(im)
{
}

double Complex::getReal() const
{
    return real;
}

double Complex::getIm() const
{
    return im;
}

void Complex::setReal(double real)
{
    this->real = real;
}

void Complex::setIm(double im)
{
    this->im = im;
}

Complex Complex::getConjugated() const
{
    Complex res(*this);
    res.im *= -1;
    return res;
}

Complex& Complex::operator+=(const Complex& rhs)
{
    real += rhs.real;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    real -= rhs.real;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    double oldReal = real;
    real = real * rhs.real - im * rhs.im;
    im = oldReal * rhs.im + im * rhs.real;
    return *this;
   
}

Complex& Complex::operator/=(const Complex& rhs)
{
    Complex conjugated = rhs.getConjugated();
    Complex otherCopy(rhs);
    *this *= conjugated;
    otherCopy *= conjugated;
    if (otherCopy.real != 0)
    {
        real /= otherCopy.real;
        im /= otherCopy.im;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& other)
{
   return  os << other.real << " " << other.im << 'i';
}

std::istream& operator>>(std::istream& is, Complex& other)
{
    return is >> other.real >> other.im;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs);
    result += rhs;
    return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs);
    result -= rhs;
    return result;
}
Complex operator*(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs);
    result *= rhs;
    return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs);
    result /= rhs;
    return result;
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
    return lhs.getReal() == rhs.getReal() && lhs.getIm() == rhs.getIm();
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
    return !(lhs == rhs);
}
