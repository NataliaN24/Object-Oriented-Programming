#pragma once
#include<iostream>

struct A
{
	int a = 5;
	int b = 10;
};

class DynamicArrayOfA
{
private:
	A* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyfrom(const DynamicArrayOfA& other);
	void movefrom(DynamicArrayOfA&& other);
	void free();
	void resize(size_t newCap);
public:
	DynamicArrayOfA();
	DynamicArrayOfA(size_t capacity);
	DynamicArrayOfA(const DynamicArrayOfA& other);
	DynamicArrayOfA& operator=(const DynamicArrayOfA& other);
	~DynamicArrayOfA();
	DynamicArrayOfA(DynamicArrayOfA&& other) noexcept;
	DynamicArrayOfA& operator=(DynamicArrayOfA&& other) noexcept;

	void pushBack(const A& newEl);
	void pushBack(A&& newEl);
	void popBack();
	void setAtIndex(const A& el, size_t index);
	void setAtIndex( A&& el, size_t index);
	size_t getSize()const;
	bool isEmpty()const;
	const A& operator[](size_t index)const;
	A& operator[](size_t index);
};