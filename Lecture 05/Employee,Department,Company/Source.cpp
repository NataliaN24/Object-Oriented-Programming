#include"Company.h"
#include"Department.h"
#include"Employee.h"
#include<iostream>


int main()
{
    Company myCompany;

    myCompany.addDepartment("HR");
    myCompany.addDepartment("Engineering");

    Employee emp1(12,"John", "Doe", 101);
    Employee emp2(15,"Jane", "Smith", 102);

    errorCode result1 = myCompany.addEmployees("HR", emp1);
    errorCode result2 = myCompany.addEmployees("Engineering", emp2);

    if (result1 == errorCode::OK) {
        std::cout << "Employee John Doe added to HR department.\n";
    }
    else {
        std::cout << "Failed to add employee to HR department.\n";
    }

    if (result2 == errorCode::OK) {
        std::cout << "Employee Jane Smith added to Engineering department.\n";
    }
    else {
        std::cout << "Failed to add employee to Engineering department.\n";
    }

    errorCode result3 = myCompany.removeDepartment("HR");
    if (result3 == errorCode::OK) {
        std::cout << "HR department removed.\n";
    }
    else {
        std::cout << "Failed to remove HR department.\n";
    }

    return 0;
}
