#include "Form.h"

void Form::copyFrom(const Form& other)
{
	this->count = other.count;
	this->capacity = other.capacity;
	controlls = new Controls * [other.capacity];
	for (int i = 0; i < other.count; i++)
	{
		controlls[i] = other.controlls[i]->clone();
	}

}

void Form::moveFrom(Form&& other)
{
	count = other.count;
	capacity = other.capacity;
	controlls = other.controlls;
	length = other.length;
	width = other.width;
	name = other.name;

	other.count = other.capacity = other.length = other.width = 0;
	other.name = " ";
	other.controlls = nullptr;
}

void Form::resize(size_t newCapacity)
{
	Controls** newControls = new Controls * [newCapacity];
	for (size_t i = 0; i < count; ++i) {
		newControls[i] = controlls[i];
	}
	delete[] controlls;
	controlls = newControls;
	capacity = newCapacity;
}

void Form::free()
{
	for (size_t i = 0; i < count; ++i) {
		delete controlls[i];
	}
	delete[] controlls;
	
}

Form::Form():length(0), width(0), name(""), count(0), capacity(0) 
{
	controlls = nullptr;
}

Form::Form(const Form& other)
{
	copyFrom(other);
}

Form::Form(Form&& other) noexcept
{
	moveFrom(std::move(other));
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Form& Form::operator=(Form&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Form::~Form()
{
	free();
}

Form::Form(unsigned int l, unsigned int w, const MyString& n, Controls** cntrls, size_t count, size_t capacity):length(l),width(w),name(n)
{
	this->count = count;
	this->capacity = capacity;
	controlls = new Controls*[capacity];
	for (int i = 0; i < count; i++)
	{
		controlls[i] = cntrls[i];
	}

}

void Form::addControl(const Controls& c)
{
	if (count == capacity)
	{
		resize(capacity * 2);
	}
	controlls[count++] = c.clone();
}

void Form::changeTheDimension(unsigned int l, unsigned int w)
{
	length = l;
	width = w;
	for (int i = 0; i < count; i++)
	{
		controlls[i]->changeDimension(l, w);
	}
}

void Form::change(size_t index)
{
	if (index < count)
	{
		controlls[index]->setDataDialog();
	}
}

void Form::display() const
{
	std::cout << "Form Name: " << name << "\n"
		<< "Length: " << length << ", Width: " << width << "\n"
		<< "Controls: " << count << "\n";

	for (size_t i = 0; i < count; ++i) {
		std::cout << "Control " << i + 1 << ": ";
		controlls[i]->display(); 
	}
}
