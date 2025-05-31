#include "Test.h"


void Test::setTest(const Questions& questions, const Answer* answersDescription, const size_t points[])
{
	this->questions = questions;
    for (int i = 0; i < MAX_NUM_QUESTIONS; i++)
    {
        this->answers[i] = answersDescription[i];
        this->points[i] = points[i];
    }

}


void Test::print() const {
    std::cout << "Test Questions and Answers:\n";

    for (int i = 0; i < MAX_NUM_QUESTIONS; ++i) {
        if (points[i] == 0) continue; 

        std::cout << "\nQuestion " << i + 1 << ": " << questions.getQuestion(i) << "\n";
        answers[i].print();
        std::cout << "Points: " << points[i] << "\n";
    }
}

void Test::runTest()
{
    for (int i = 0; i < MAX_NUM_QUESTIONS; i++)
    {
        std::cout << "Questions " << i + 1 << ": " << questions.getQuestion(i) << "\n";
        answers[i].print();

        int choice;
        std::cout << "Enter your choice:";
        std::cin >> choice;
        if (answers[i].isCorrect(choice)) {
            std::cout << "Correct! +" << points[i] << " points.\n";
            totalScore += points[i];
        }
        else {
            std::cout << "Incorrect. No points.\n";
        }
    }

}

size_t  Test::getTotalPointsOfUser() const
{
    return totalScore;
}
