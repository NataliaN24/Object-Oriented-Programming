#include "Test.h"

int main() {
    int ids[] = { 1, 2, 3 };
    char titles[3][MAX_NUM_TITLE + 1] = {
        "Capital of France?",
        "2 + 2 equals?",
        "Sky color?"
    };

    Questions q;
    q.setTitlesInQuestions(ids, titles);

    char a1[MAX_NUM_OPTIONS][MAX_NUM_ANSWER_DESCRIPTION + 1] = {
        "Berlin", "Madrid", "Paris", "London"
    };
    char a2[MAX_NUM_OPTIONS][MAX_NUM_ANSWER_DESCRIPTION + 1] = {
        "3", "4", "5", "6"
    };
    char a3[MAX_NUM_OPTIONS][MAX_NUM_ANSWER_DESCRIPTION + 1] = {
        "Red", "Blue", "Green", "Yellow"
    };

    Answer answers[MAX_NUM_QUESTIONS] = {
        Answer(a1, Options::C),
        Answer(a2, Options::B),
        Answer(a3, Options::B)
    };

    size_t pts[MAX_NUM_QUESTIONS] = { 5, 2, 3 };

    Test test;
    test.setTest(q, answers, pts);
    test.print();
    test.runTest();

    std::cout << "Total points earned: " << test.getTotalPointsOfUser() << "\n";

    return 0;
}
