#pragma once
#include<iostream>

constexpr int rowsValue = 2;
constexpr int colsValue = 2;

class Matrix
{
	int rows;
	int cols;
	int** matrix;
	void allocate();
	void copyFrom(const Matrix& other);
	void free();
public:

	Matrix();
	Matrix(int m, int n);
	Matrix& operator=(const Matrix& other);
	Matrix(const Matrix& other);
	~Matrix();

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(double number);
	int* operator[](int index);
	const int* operator[](int index)const;
	bool operator==(const Matrix& other)const;
	bool operator!=(const Matrix& other)const;
	operator bool()const;
	void print()const;

};
Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, double number);


