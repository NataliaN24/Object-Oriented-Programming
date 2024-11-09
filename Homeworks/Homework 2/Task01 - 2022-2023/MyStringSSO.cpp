#include "MyStringSSO.h"
#include<iostream>
#include<cstring>

void  MyStringSSO::copyFrom(const MyStringSSO& other) 
{
	if (other.length <= max_length) 
	{
		std::memcpy(this, &other, sizeof(other));
	}
	else
	{
		string.data = expand(other.string.data, other.length + 1);
		length = other.length;
		string.capacity = length;
	}
}

void  MyStringSSO::moveFrom(MyStringSSO&& other) 
{
	if (other.length <= max_length)
	{
		std::memcpy(this, &other, sizeof(other));
	}
	else 
	{
		string.data = other.string.data;
		string.capacity = other.string.capacity;
		length = other.length;
		
		other.string.data = nullptr;
		other.string.capacity = 0;
		other.length = 0;
	}
}

void  MyStringSSO::free() 
{
	if (length > max_length) 
	{
		delete[] string.data;
		string.data = nullptr;
	}
	length = 0;
}

void MyStringSSO::check(int n)const 
{
	if (n < 0 || length <= n) 
	{
		throw std::out_of_range("Invalid !");
	}
}

char* expand(const char* data, int n)
{
	char* ptr = new char[n];
	strcpy(ptr, data);
	return ptr;
}

MyStringSSO::MyStringSSO() : length{ 0 }
{
	ch[0] = 0;
}

MyStringSSO::MyStringSSO(const char* content) :length{ std::strlen(content) } 
{
	char* memory;
	if (length > max_length)
	{
		string.data = new char[length + 1];
		string.capacity = length;
		memory = string.data;
	}
	else
	{
		memory = ch;
	}
	strcpy(memory, content);
}

MyStringSSO::MyStringSSO(const MyStringSSO& other) 
{
	copyFrom(other);
}

MyStringSSO::MyStringSSO( MyStringSSO&&other) 
{
	moveFrom(std::move(other));
}

MyStringSSO::~MyStringSSO() 
{
	free();
}

MyStringSSO& MyStringSSO::operator=(const MyStringSSO& other) 
{ 
	if (this != &other)
	{
		char* ptr = (max_length < length) ? string.data : nullptr;
		copyFrom(other);
		delete[]ptr;
	}
	return *this;
}

MyStringSSO& MyStringSSO:: operator=(MyStringSSO&& other) 
{
	if (this != &other) 
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyStringSSO& MyStringSSO::operator+=(const MyStringSSO& other)
{
	std::size_t new_length = length + other.length;
	if (new_length <= max_length) 
	{
		strcpy(ch + length, other.c_str());
	}
	else
	{
		char* ptr = (max_length < length) ? string.data : nullptr;
		string.data = expand(c_str(), new_length + 1);
		delete[] ptr;
		string.capacity = new_length;
		strcpy(string.data + length, other.c_str());
	}
	length = new_length;
	return *this;
}

MyStringSSO operator+(const MyStringSSO& lhs, const MyStringSSO& rhs)
{
	MyStringSSO tmp = lhs;
	return tmp += rhs;
}

char& MyStringSSO:: operator[](size_t index) 
{

	if (index >= length)
	{
		throw std::out_of_range("Index is out of range!");
	}
	return (length <= max_length) ? ch[index] : string.data[index];
}

char  MyStringSSO::operator[](size_t index) const 
{
	if (index >= length) 
	{
		throw std::out_of_range("Index is out of range!");
	}
	return (length <= max_length) ? ch[index] : string.data[index];
}

MyStringSSO MyStringSSO::substr(size_t begin, size_t howMany) const 
{
	if (begin + howMany > length) 
	{
		throw std::length_error("Substring is out of range!");
	}
	MyStringSSO result;
	result.length = howMany;
	if (howMany <= max_length) 
	{
		for (int i = 0; i < howMany; i++) 
		{
			result.ch[i] = ch[begin + i];
		}
		result.ch[howMany] = '\0';
	}
	else
	{
		result.string.data = new char[howMany + 1];
		result.string.capacity = howMany;
		for (int i = 0; i < howMany; i++)
		{
			result.string.data[i] = string.data[begin + i];
		}
		result.string.data[howMany] = '\0';
	}
	return result;
}

const char* MyStringSSO::c_str() const 
{
	return length <= max_length ? ch : string.data;
}

std::istream& operator>>(std::istream& is, MyStringSSO& str) 
{
	char buff[1024];
	is >> buff;
	str.free();
	str.length = strlen(buff);
	if (str.length <= MyStringSSO::max_length)
	{
		strcpy(str.ch, buff);
	}
	else 
	{
		str.string.data = expand(buff, str.length + 1);
		str.string.capacity = str.length;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const MyStringSSO& str)
{
	return os << str.c_str();
}

bool operator<(const MyStringSSO& lhs, const MyStringSSO& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const MyStringSSO& lhs, const MyStringSSO& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator<=(const MyStringSSO& lhs, const MyStringSSO& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyStringSSO& lhs, const MyStringSSO& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator==(const MyStringSSO& lhs, const MyStringSSO& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyStringSSO& lhs, const MyStringSSO& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

void MyStringSSO::clear() 
{
	free();
}

bool MyStringSSO::empty()const 
{
	return length == 0;
}

void MyStringSSO::append(char symbol) 
{
	if (length < max_length)
	{
		ch[length] = symbol;
		++length;
		ch[length] = '\0';
	}
	else
	{
		char* new_data = new char[length + 2]; 
		std::memcpy(new_data, ch, length); 
		new_data[length] = symbol; 
		new_data[length + 1] = '\0'; 
		delete[] string.data; 
		string.data = new_data; 
		string.capacity = length + 2; 
		++length; 
	}
}

int  MyStringSSO::compare(const MyStringSSO& other)const 
{
	return strcmp(c_str(), other.c_str());
}