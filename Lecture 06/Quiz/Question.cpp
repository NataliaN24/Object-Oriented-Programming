#include "Question.h"

Question::Question(const char* task, const char* a1, const char* a2, const char* a3, const char* a4, int correct):answers(a1,a2,a3,a4),correctAnswer(correct)
{
    this->task = new char[strlen(task) + 1];
    strcpy(this->task, task);
}

Question::Question(const Question& other)
{
    copyDynamic(other);
}

Question& Question::operator=(const Question& other)
{
    if (this != &other)
    {
        free();
        copyDynamic(other);
   }
    return *this;
}

Question::~Question()
{
    free();
}

void Question::free()
{
    delete[]task;
}

void Question::copyDynamic(const Question& other)
{
    this->task = new char[strlen(other.task) + 1];
    strcpy(this->task, other.task);
    correctAnswer = other.correctAnswer;
    answers = other.answers;


}
