#pragma once
#pragma warning (disable : 4996)
#include <cstring>
class Question
{
public:
	struct Answer {
		char text[127 + 1] = " ";
		Answer(const char* str)
		{
			if (!str || std::strlen(str) > 127)
			{
				return;
			}
			strcpy(text, str);
		}
	};
	struct Answers
	{
		Answer answers[4];
		Answers(const char* a1 = nullptr, const char* a2 = nullptr,
			const char* a3 = nullptr, const char* a4 = nullptr) :
			answers{ Answer(a1), Answer(a2), Answer(a3), Answer(a4) }{}
	};

	Question() = default;
	Question(const char* task, const char* a1, const char* a2, const char* a3, const char* a4, int correct);
	Question(const Question& other);
	Question& operator=(const Question& other);
	~Question();

private:
	char* task;
	Answers answers;
	int correctAnswer;

	void free();
	void copyDynamic(const Question& other);
};

