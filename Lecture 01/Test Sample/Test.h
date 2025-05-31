#pragma once
#include"Answers.h"
#include"Questions.h"

constexpr int MAX_POINTS = 10;
class Test
{
	Questions questions;
	Answer answers[MAX_NUM_QUESTIONS];
	size_t points[MAX_NUM_QUESTIONS];

public:
	Test() = default;
	void setTest(const Questions&questions,const Answer *answersDescription,const size_t points[]);
	void print()const;
};

