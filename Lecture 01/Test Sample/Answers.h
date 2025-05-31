#pragma once
#include<iostream>
#pragma warning(disable:4996)

constexpr int MAX_NUM_OPTIONS = 4;
constexpr int MAX_NUM_ANSWER_DESCRIPTION = 50;

struct Answer {

	char answerDescription[MAX_NUM_OPTIONS][MAX_NUM_ANSWER_DESCRIPTION + 1]{};

public:

	Answer();
	Answer(char answer[][MAX_NUM_ANSWER_DESCRIPTION + 1]);
	void setAnswerForEachOption( char answer[][MAX_NUM_ANSWER_DESCRIPTION + 1]);
	void print()const;

};
