#pragma once
#include<iostream>
#include"StringPiece.h"
#include"MyString.h"

class StringCollection
{
private:
	StringPiece* pieces;
	size_t capacity;
	size_t size;

	void resize(size_t newCapacity);
	void copyFrom(const StringCollection&);
	void moveFrom(StringCollection&&);
	void free();

public:
	StringCollection() : pieces(nullptr), capacity(0), size(0) {}
	StringCollection(const StringCollection&);
	StringCollection& operator=(const StringCollection&);
	StringCollection(int );
	StringCollection(const char* );
	~StringCollection();

	StringCollection(StringCollection&& )noexcept;
	StringCollection& operator=(StringCollection&& ) noexcept;

	void addNewPiece(const StringPiece& str);
	void exchangePieces(int index1, int index2);
	void deleteByIndex(int index);
	void addPieceAt(const StringPiece& str, int index);
	size_t getLength()const;

	MyString getString()const;

};