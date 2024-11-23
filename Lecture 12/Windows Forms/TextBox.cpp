#include "TextBox.h"

TextBox::TextBox():text(" ")
{

}

void TextBox::display() const
{
	Controls::display();
	std::cout << "Text:" << text.c_str();
}

TextBox::TextBox(unsigned int l, unsigned int w, unsigned int x, unsigned int y, const  MyString& name, const MyString &text):Controls(l,w,x,y,name)
{
	setText(text);
}


void TextBox::setDataDialog()
{
	std::cout << "Enter the text:" << std::endl;
	MyString txt;
	std::cin >> txt;
	setText(txt);
}

void TextBox::setText(const MyString& txt)
{
	text = txt;
}

Controls* TextBox::clone() const
{
	return new TextBox(*this);
}
