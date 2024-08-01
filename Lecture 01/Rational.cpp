#include <iostream>

struct Rational
{
    int nominator;
    int denominator;
};

bool isValid(const Rational& num)
{
    return num.denominator != 0;
}

void printRational(const Rational& num)
{
    std::cout << num.nominator << "/" << num.denominator << std::endl;
}

unsigned getGCD(unsigned a, unsigned b)
{
    if (a < b)
    {
        std::swap(a, b);
    }
    while (b != 0)
    {
        unsigned temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void rationalize(Rational& rat)
{
    if (!isValid(rat))
    {
        return;
    }
    unsigned gcd = getGCD(abs(rat.nominator), abs(rat.denominator));
    rat.nominator /= gcd;
    rat.denominator /= gcd;

    if (rat.denominator < 0)
    {
        rat.nominator *= -1;
        rat.denominator *= -1;
    }
}

Rational& plusRational(Rational& lhs, const Rational& rhs)
{
    if (!isValid(lhs) || !isValid(rhs))
    {
        throw std::invalid_argument("Invalid rational number");
    }
    lhs.nominator = lhs.nominator * rhs.denominator + rhs.nominator * lhs.denominator;
    lhs.denominator *= rhs.denominator;
    rationalize(lhs);
    return lhs;
}

Rational plus(const Rational& lhs, const Rational& rhs)
{
    if (!isValid(lhs) || !isValid(rhs))
    {
        throw std::invalid_argument("Invalid rational number");
    }
    Rational result = lhs;
    return plusRational(result, rhs);
}

Rational& multiplyRational(Rational& lhs, const Rational& rhs)
{
    if (!isValid(lhs) || !isValid(rhs))
    {
        throw std::invalid_argument("Invalid rational number");
    }
    lhs.nominator *= rhs.nominator;
    lhs.denominator *= rhs.denominator;
    rationalize(lhs);
    return lhs;
}

Rational multiply(const Rational& lhs, const Rational& rhs)
{
    if (!isValid(lhs) || !isValid(rhs))
    {
        throw std::invalid_argument("Invalid rational number");
    }
    Rational result = lhs;
    return multiplyRational(result, rhs);
}

Rational distribute(const Rational& factor, const Rational& lhs, const Rational& rhs)
{
    if (!isValid(factor) || !isValid(lhs) || !isValid(rhs))
    {
        throw std::invalid_argument("Invalid rational number");
    }
    Rational left = multiply(factor, lhs);
    Rational right = multiply(factor, rhs);
    return plus(left, right);
}

int main()
{
    Rational r1 = { 2, 3 };
    Rational r2 = { 3, 4 };
    Rational r3 = { 5, 6 };

    Rational sum = plus(r1, r2);
    std::cout << "Sum: ";
    printRational(sum);

    Rational product = multiply(r1, r2);
    std::cout << "Product: ";
    printRational(product);

    Rational distributed = distribute(r3, r1, r2);
    std::cout << "Distributed: ";
    printRational(distributed);

    return 0;
}
