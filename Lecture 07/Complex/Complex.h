#pragma once
#include<iostream>

class Complex
{
	double real;
	double im;

public:
	Complex();
	Complex(double real, double im);

	double getReal()const;
	double getIm()const;
	void setReal(double real);
	void setIm(double im);

	Complex getConjugated()const;

	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Complex& other);
	friend std::istream& operator>>(std::istream& is, Complex& other);

};
Complex operator+(const Complex & lhs, const Complex & rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);