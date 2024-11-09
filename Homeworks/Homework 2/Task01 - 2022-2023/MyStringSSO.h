#pragma once
#pragma warning (disable: 4996)
#include<iostream>

class MyStringSSO
{
private:
	static const int max_length = 15;
	size_t length;
	union 
	{
		struct
		{
			char* data;
			size_t capacity; 
		} string;
		char ch[max_length + 1];
	};
	void copyFrom(const MyStringSSO& );
	void moveFrom(MyStringSSO&& );
	void free();
	void check(int )const;

public:
	MyStringSSO();
	MyStringSSO(const char* );
	MyStringSSO(const MyStringSSO& );
	~MyStringSSO();
	MyStringSSO& operator=(const MyStringSSO& );

	MyStringSSO(MyStringSSO&&);
	MyStringSSO& operator=(MyStringSSO&&);
	
	MyStringSSO& operator+=(const MyStringSSO& );
	char& operator[](size_t );
	char operator[](size_t ) const;

	MyStringSSO substr(size_t , size_t ) const;
	
	const char* c_str() const;
	friend std::istream& operator>>(std::istream&, MyStringSSO&);
	
	void clear();
	bool empty()const;
	void append(char );
	int compare(const MyStringSSO& )const;

};
char* expand(const char* , int );
std::ostream& operator<<(std::ostream& , const MyStringSSO& );
MyStringSSO operator+(const MyStringSSO& , const MyStringSSO& );
bool operator<(const MyStringSSO& , const MyStringSSO& );
bool operator>(const MyStringSSO , const MyStringSSO& );
bool operator<=(const MyStringSSO& , const MyStringSSO& );
bool operator>=(const MyStringSSO& , const MyStringSSO& );
bool operator==(const MyStringSSO& , const MyStringSSO& );
bool operator!=(const MyStringSSO& , const MyStringSSO& );