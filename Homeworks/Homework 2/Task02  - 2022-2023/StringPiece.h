#pragma once
#include <iostream>
#pragma warning (disable: 4996)

class StringPiece
{
private:
	static const int max_length = 16;
	char value[max_length];
	size_t size;

public:
    StringPiece() : value{ '\0' }, size(0) {};
    StringPiece(const char* );

    const char* getValue() const;
    size_t getSize()const;
    void setValue(const char* );
   
    void removeFirst(int );
    void removeLast(int );
    void changeSymbol(char ,int );
    void print()const;

    StringPiece& operator<<( const char* );
    StringPiece& operator>>(const char* );
    StringPiece& operator<<(int );
    StringPiece& operator>>(int );
};