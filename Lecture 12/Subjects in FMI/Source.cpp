#include "SubjectContainer.h"
#include "OOP.h"
#include "UP.h"
#include "DSTR.h"
#include "Geometry.h"
#include "Calculus.h"
#include <iostream>

int main() {
    SubjectContainer container;

    MyString assistants[] = { MyString("Ivanov"), MyString("Petrova") };

    container.addSubject(OOP(MyString("ООП"), MyString("Dr. Stoyanova"), assistants, 2, 100, 5));
    container.addSubject(OOP(MyString("ООП"), MyString("Dr. Stoyanova"), assistants, 2, 100, 10));
    container.addSubject(UP(MyString("УП"), MyString("Dr. Stoyanova"), assistants, 2, 100));
    container.addSubject(DSTR(MyString("ДСТР2"), MyString("Prof. Ivanov"), assistants, 2, 100));
    container.addSubject(Geometry(MyString("ГЕОМЕТРИЯ"), MyString("Dr. Stoyanova"), assistants, 2, 100));
    container.addSubject(Calculus(MyString("ДИС"), MyString("Dr. Dimitrova"), assistants, 2, 100));

    std::cout << "Total subjects in container: " << container.getCount() << std::endl;

    SubjectInFMI* mostFamous = container.getTheMostFamousSubject();
    if (mostFamous) {
        std::cout << "Most frequent lecturer: " << mostFamous->getLecturerName().c_str() << std::endl;
        std::cout << "Subject name: ";
        mostFamous->getSubjectName();
    }
    else {
        std::cout << "No subjects found." << std::endl;
    }

    return 0;
}
