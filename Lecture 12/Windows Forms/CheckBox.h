#pragma once
#include"Controls.h"

class CheckBox:public Controls
{
	MyString text;
	bool condition;//0 off 1 on

public:
	CheckBox();
	CheckBox(unsigned int l, unsigned int w, unsigned int x, unsigned int y, const  MyString& name, const MyString& text,bool cond);
	virtual void setDataDialog() override;
	void setText(const MyString& txt);
	void display()const;
	virtual Controls* clone()const override;
};

