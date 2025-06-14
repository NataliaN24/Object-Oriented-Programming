#pragma once
#include<iostream>

class Vector2D
{
	double x;
	double y;
public:
	Vector2D();
	Vector2D(double _x, double _y);

	double getX()const;
	double getY()const;

	Vector2D& operator+=(const Vector2D& other);
	friend Vector2D operator*(double number, const Vector2D& vector);

};
Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
Vector2D operator*(const Vector2D& lhs, double n);
bool operator==(const Vector2D& lhs, const Vector2D& rhs);
bool operator!=(const Vector2D& lhs, const Vector2D& rhs);
double operator^(const Vector2D& lhs, const Vector2D& rhs);
