#pragma once
#include<iostream>
#pragma warning(disable:4996)

constexpr int MAX_NUM_QUESTIONS = 3;
constexpr int MAX_NUM_TITLE = 50;

class Questions
{
	int questionsInTest[MAX_NUM_QUESTIONS]={};
	char titles[MAX_NUM_QUESTIONS][MAX_NUM_TITLE + 1]={};

public:
	Questions() = default;
	Questions(int* questions, char titles[][MAX_NUM_TITLE + 1]);

	void setTitlesInQuestions(const int* questions, char titles[][MAX_NUM_TITLE+1]);

	void printQuestions()const;

	const char* getQuestion(int index)const;

};
