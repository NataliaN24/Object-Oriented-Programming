#include "Quiz.h"
#include<iostream>

void Quiz::free()
{
    delete[]questions;
}

void Quiz::copyfrom(const Quiz& other)
{
    capacity = other.capacity;
    size = other.size;
    questions = new Question[capacity];
    for (int i = 0; i < capacity; i++)
    {
        questions[i] = other.questions[i];
    }
}

Quiz::Quiz()
{
    free();
}

Quiz::Quiz(const Quiz& other)
{
    copyfrom(other);
}

Quiz& Quiz::operator=(const Quiz& other)
{
    if (this != &other)
    {
        free();
        copyfrom(other);
   }
    return *this;
}

Quiz::~Quiz()
{
    free();
}

Quiz::Quiz(size_t maxQuestions)
{
    size = 0;
    questions = new Question[maxQuestions];
    capacity = maxQuestions;
}

void Quiz::addQuestion(const Question& q)
{
    if (size >= capacity)
    {
        return;
    }
    questions[size++] = q;
}

size_t Quiz::getSize() const
{
    return size;
}

size_t Quiz::isFull() const
{
    return size == capacity;
}
