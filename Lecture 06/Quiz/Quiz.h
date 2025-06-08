#pragma once
#include"Question.h"

class Quiz
{
	Question* questions;
	size_t size;
	size_t capacity;

	void free();
	void copyfrom(const Quiz& other);
public:
	Quiz();
	Quiz(const Quiz& other);
	Quiz& operator=(const Quiz& other);
	~Quiz();
	Quiz(size_t maxQuestions);
	void addQuestion(const Question& q);
	size_t getSize()const;
	size_t isFull()const;

};

