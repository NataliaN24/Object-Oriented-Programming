#include "Answers.h"

Answer::Answer()
{
}

Answer::Answer( char answer[][MAX_NUM_ANSWER_DESCRIPTION + 1])
{
	setAnswerForEachOption( answer);
}

void Answer::setAnswerForEachOption( char answer[][MAX_NUM_ANSWER_DESCRIPTION + 1])
{
	for (int i = 0; i < MAX_NUM_OPTIONS; i++)
	{
		std::strcpy(answerDescription[i], answer[i]);
	}
}

void Answer::print() const {
	const char optionLabels[] = { 'A', 'B', 'C', 'D' };
	for (int i = 0; i < MAX_NUM_OPTIONS; ++i) {
		std::cout << "Option " << optionLabels[i] << ": " << answerDescription[i] << "\n";
	}
}
