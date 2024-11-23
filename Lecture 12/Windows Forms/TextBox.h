#pragma once
#include"Controls.h"

class TextBox:public Controls
{
	MyString text;

public:
	TextBox();
	void display()const;
	TextBox(unsigned int l, unsigned int w, unsigned int x, unsigned int y,const  MyString& name,const MyString& text);
	virtual void setDataDialog() override;
	void setText(const MyString&txt);
	virtual Controls* clone()const override;

};

