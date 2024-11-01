#pragma once
#include"MyString.h"

class Product
{
protected:
	MyString product_name;
public:

	Product();
	Product(const MyString& name);
	unsigned getLength()const;
	const MyString& getName()const;

};