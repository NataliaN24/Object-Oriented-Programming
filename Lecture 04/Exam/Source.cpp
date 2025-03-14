#include "Task.h"
#include "Exam.h"

int main()
{
    Task t1("Math", "Solve integrals", 10);
    Task t2("Physics", "Explain Newton's laws", 15);
    Task t3("Chemistry", "Balance chemical equations", 12);

    Exam exam;
    exam.addTask(t1);
    exam.addTask(t2);
    exam.addTask(t3);

    exam.setMinPoints(20);

    const char* fileName = "exam_data.bin";

    exam.writeToFile(fileName);

    Exam loadedExam;
    loadedExam.readFromFile(fileName);

    std::cout << "Max possible points: " << exam.getMax() << std::endl;

    return 0;
}
