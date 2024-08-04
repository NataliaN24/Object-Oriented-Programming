#include "Interval.h"
#include <cmath>


Interval::Interval():Interval(0,0)
{
}

Interval::Interval(int a, int b)
{
    setA(a);
    setB(b);
}

void Interval::setA(int a)
{
    if (a > this->b)
    {
        a = this->b;
    }
    this->a = a;
}

void Interval::setB(int b)
{
    if (b < this->a)
    {
        b = this->a;
    }
    this->b = b;
}

int Interval::getA() const
{
    return a;
}

int Interval::getB() const
{
    return b;
}

bool Interval::isInInterval(int x) const
{
    return a <= x && x <= b;
}

namespace
{
	bool isPrime(int n)
	{
		if (n < 2)
			return false;

		double temp = sqrt(n);

		for (int i = 2; i <= temp; i++)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}

	int reverse(int n)
	{
		int reversed = 0;

		while (n != 0)
		{
			reversed = reversed * 10 + n % 10;
			n /= 10;
		}
		return reversed;
	}

	bool isPalindrome(int n)
	{
		return n == reverse(n);
	}
}

unsigned Interval::getCountCondition(bool(*pred)(int)) const
{
	unsigned count = 0;
	for (int i = a; i <= b; i++)
	{
		if (pred(i))
		{
			count++;
		}
	}
	return count;
}

unsigned Interval::getPrimesCount() const
{
	return getCountCondition(isPrime);
}

unsigned Interval::getPalindromesCount() const
{
	return getCountCondition(isPalindrome);
}

bool Interval::isSubinterval(const Interval& other) const
{
	return a >= other.a && b <= other.b;
}

Interval intersection(const Interval& lhs, const Interval& rhs)
{
	int newA =std:: max(lhs.getA(), rhs.getA());
	int newB = std::min(lhs.getB(), rhs.getB());

	if (newA > newB)
	{
		throw "Error";
	}
	return Interval(newA, newB);

}