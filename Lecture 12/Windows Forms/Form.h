#pragma once
#include<iostream>
#include"MyString.h"
#include"Controls.h"

class Form
{
	unsigned int length;
	unsigned int width;
	MyString name;
	Controls** controlls;
	size_t count;
	size_t capacity;

	void copyFrom(const Form& other);
	void moveFrom(Form&& other);
	void resize(size_t newCapacity);
	void free();

public:
	Form();
	Form(const Form& other);
	Form(Form&& other)noexcept;
	Form& operator=(const Form& other);
	Form& operator=(Form&& other);
	~Form();

	Form(unsigned int l, unsigned int w, const MyString& n, Controls** cntrls,size_t count,size_t capacity);
	void addControl(const Controls& c);
	void changeTheDimension(unsigned int l, unsigned int w);
	void change(size_t index);
	void display()const;


};

