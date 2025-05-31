#include "Test.h"

int main() {
   
    int qIDs[MAX_NUM_QUESTIONS] = { 1, 2, 3 };
    char qTitles[MAX_NUM_QUESTIONS][MAX_NUM_TITLE + 1] = {
        "Capital of France?",
        "5 + 7 equals?",
        "Color of the sky?"
    };
    Questions qs(qIDs, qTitles);

    Answer answers[MAX_NUM_QUESTIONS];

    char opts1[MAX_NUM_OPTIONS][MAX_NUM_ANSWER_DESCRIPTION + 1] = {
        "Paris", "Rome", "Berlin", "Madrid"
    };
    char opts2[MAX_NUM_OPTIONS][MAX_NUM_ANSWER_DESCRIPTION + 1] = {
        "10", "11", "12", "13"
    };
    char opts3[MAX_NUM_OPTIONS][MAX_NUM_ANSWER_DESCRIPTION + 1] = {
        "Red", "Blue", "Green", "Yellow"
    };

    answers[0] = Answer(opts1);
    answers[1] = Answer(opts2);
    answers[2] = Answer(opts3);

    size_t pts[MAX_NUM_QUESTIONS] = { 5, 3, 2 };

    Test test;
    test.setTest(qs, answers, pts);
    test.print();

    return 0;
}
