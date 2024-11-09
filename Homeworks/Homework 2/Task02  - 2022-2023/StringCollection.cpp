#include "StringCollection.h"
#include<iostream>
#include<cstring>

void StringCollection::resize(size_t newCapacity)
{
    if (newCapacity > capacity)
    {
        StringPiece* newPieces = new StringPiece[newCapacity];
        for (size_t i = 0; i < size; i++) 
        {
            newPieces[i] = pieces[i];
        }
        delete[]pieces;
        pieces = newPieces;
        capacity = newCapacity;
    }
}

void StringCollection::copyFrom(const StringCollection& other)
{
    pieces = new StringPiece[other.capacity];
    for (size_t i = 0; i < other.size; i++)
    {
        pieces[i] = other.pieces[i];
    }
    capacity = other.capacity;
    size = other.size;
}

void StringCollection::moveFrom( StringCollection&& other )
{
    pieces = other.pieces;
    other.pieces = nullptr;
    capacity = other.capacity;
    size = other.size;
}

void  StringCollection::free()
{
    delete[] pieces;
    pieces = nullptr;
    capacity = 0;
    size = 0;
}

StringCollection::StringCollection(const StringCollection&other) 
{
    copyFrom(other);
}

StringCollection& StringCollection:: operator=(const StringCollection&other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

StringCollection::StringCollection(int initialCapacity)
{
    pieces = new StringPiece[initialCapacity];
    capacity = initialCapacity;
    size = 0;
}

StringCollection::StringCollection(const char* str)
{
    size_t len = strlen(str);
    size_t numOfPieces = len / 16 + (len % 16 != 0);
    pieces = new StringPiece[numOfPieces];
    capacity = numOfPieces;
    size = numOfPieces;

    for (int i = 0; i < numOfPieces - 1; i++)
    {
        pieces[i].setValue(str + i * 16);
    }

    size_t lastPieceLength = len % 16;

    if (lastPieceLength == 0) 
    {
        pieces[numOfPieces - 1].setValue(" ");
    }
    else
    {
        char lastPiece[17];
        strcpy(lastPiece, str + (numOfPieces - 1) * 16); 
        lastPiece[lastPieceLength] = '\0';
        pieces[numOfPieces - 1].setValue(lastPiece);
    }
}

StringCollection::~StringCollection() 
{
    free();
}

StringCollection::StringCollection(StringCollection&& other)noexcept 
{
    moveFrom(std::move(other));
}

StringCollection& StringCollection:: operator=(StringCollection&& other) noexcept
{
    if (this != &other) 
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void StringCollection::addNewPiece(const StringPiece& str)
{
    if (str.getSize() == 0) 
    {
        pieces[size++].setValue(" ");
    }
    else 
    {
        if (size == capacity) 
        {
            resize(capacity * 2);
        }
        pieces[size++] = str;
    }
}

void swap(StringPiece&a, StringPiece& b) 
{
    StringPiece temp(a);
    a = b;
    b = temp;
}

void StringCollection::exchangePieces(int index1, int index2)
{
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) 
    {
        throw std::out_of_range("Index is out of range!");
    }
    swap(pieces[index1], pieces[index2]);
}

void StringCollection::deleteByIndex(int index)
{

    if (index < 0 || index >= size) 
    {
        throw std::out_of_range("Index is out of range!");
    }
    pieces[index].setValue(" ");
}

void StringCollection::addPieceAt(const StringPiece& str, int index) {

    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index is out of range!");
    }
    if (size == capacity) 
    {
        resize(capacity * 2);
    }
    for (size_t i = size; i > index; i--) 
    {
        pieces[i] = pieces[i - 1];
    }
    pieces[index] = str;
    size++;
}

size_t StringCollection::getLength()const
{
    size_t length = 0;
    for (size_t i = 0; i < size; i++)
    {
        length += pieces[i].getSize();
    }
    return length;
}

MyString StringCollection::getString()const 
{
    MyString result;
    for (size_t i = 0; i < size; i++) 
    {
        result += pieces[i].getValue();
    }
    if (pieces[size - 1].getSize()==0) {
        result += "                    "; 
    }
    return result;
}