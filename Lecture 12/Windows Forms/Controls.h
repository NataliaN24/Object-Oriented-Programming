#pragma once
#include"MyString.h"

class Controls
{
	unsigned int length;
	unsigned int width;
	unsigned int x;
	unsigned int y;
	MyString name;
	
public:
	Controls();
	Controls(unsigned int len, unsigned int wide, unsigned int x, unsigned int y,const MyString& name);
	virtual void display()const;
	void changeDimension(unsigned int l,unsigned int w);
	virtual void setDataDialog()=0;
	virtual ~Controls()=default;
	virtual Controls* clone()const = 0;
};