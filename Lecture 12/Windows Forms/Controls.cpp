#include "Controls.h"

Controls::Controls():name(" ")
{
	length = width = x = y = 0;
}

Controls::Controls(unsigned int len, unsigned int wide, unsigned int x, unsigned int y, const MyString& name)
	: length(len), width(wide), x(x), y(y), name(name) { }


void Controls::display() const
{
	std::cout << "Control's name:" << name.c_str() << " Length: " << length << " Width: " << width << " Location:(" << x << "," << y << ")" << std::endl;
}

void Controls::changeDimension(unsigned int l, unsigned int w)
{
	this->length = l;
	this->width = w;
}
