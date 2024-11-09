#pragma once
#include<iostream>

class Set
{
private:

    int* elements;
    int size;
	
    void copyFrom(const Set& other);
    void moveFrom(Set&& other)noexcept;
    void free();

public:

	Set();
	Set( int* elements, int size);
	Set(const Set& other);
	Set(Set&& other)noexcept;
	Set& operator= (const Set& other);
	Set& operator=(Set&& other)noexcept;

	virtual bool contains(int element)const = 0;
	virtual int nextElement() =0;

	virtual~Set();
};