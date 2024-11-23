#include "CheckBox.h"

CheckBox::CheckBox()
{
	setText(" ");
	condition = false;
}

CheckBox::CheckBox(unsigned int l, unsigned int w, unsigned int x, unsigned int y, const MyString& name, const MyString& text, bool cond):Controls(l, w, x, y, name)
{
	setText(text);
	condition = cond;
}

void CheckBox::setDataDialog()
{
	std::cout << "Enter 1 for on :" << std::endl;
	unsigned int num;
	std::cin >> num;
	if (num == 1)
	{
		condition = true;
	}
	else
	{
		condition = false;
	}
}

void CheckBox::setText(const MyString& txt)
{
	text = txt;
}

void CheckBox::display() const
{
	Controls::display();
	std::cout << "text:" << text.c_str() << "condition:" << condition << std::endl;
}

Controls* CheckBox::clone() const
{
	return new CheckBox(*this);
}
