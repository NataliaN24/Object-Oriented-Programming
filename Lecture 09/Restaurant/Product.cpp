#include "Product.h"

Product::Product():product_name()
{
}

Product::Product(const MyString& name):product_name(name)
{
	
}

unsigned Product::getLength() const
{
	return product_name.getSize();
}

const MyString& Product::getName() const
{
	return product_name;
}
