#include "Questions.h"


Questions::Questions(int* questions, char titles[][MAX_NUM_TITLE + 1])
{
    setTitlesInQuestions(questions, titles);
}

void Questions::setTitlesInQuestions(const int* questions, char titles[][MAX_NUM_TITLE + 1])
{
    for (int i = 0; i < MAX_NUM_QUESTIONS; i++)
    {
        this->questionsInTest[i] = questions[i];
        std::strcpy(this->titles[i], titles[i]);
    }
}



void Questions::printQuestions() const
{
    for (int i = 0; i < MAX_NUM_QUESTIONS; i++)
    {
        std::cout << questionsInTest[i] << " " << titles[i] << std::endl;
    }
}

const char* Questions::getQuestion(int index) const
{
    if (index<0 || index>MAX_NUM_QUESTIONS)
    {
        return nullptr;
    }
    return titles[index];
}
