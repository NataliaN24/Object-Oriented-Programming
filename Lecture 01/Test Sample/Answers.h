#pragma once
#include<iostream>
#pragma warning(disable:4996)

constexpr int MAX_NUM_OPTIONS = 4;
constexpr int MAX_NUM_ANSWER_DESCRIPTION = 50;

enum class Options {
	A,
	B,
	C,
	D
};

struct Answer {

	char answerDescription[MAX_NUM_OPTIONS][MAX_NUM_ANSWER_DESCRIPTION + 1]{};
	Options correctOption;
public:

	Answer();
	Answer(char answer[][MAX_NUM_ANSWER_DESCRIPTION + 1], Options correct);
	void setAnswerForEachOption( char answer[][MAX_NUM_ANSWER_DESCRIPTION + 1],Options correct);
	void print()const;
	bool isCorrect(int choice)const;


};
