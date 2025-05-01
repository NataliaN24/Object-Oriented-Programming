#include "Soldier.h"

void Soldier::free()
{
    delete[] name;
    name = nullptr;
}

void Soldier::copyFrom(const Soldier& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    age = other.age;
    combatSkills = other.combatSkills;
    salary = other.salary;
}

Soldier::Soldier() : name(nullptr), age(0), combatSkills(0), salary(0)
{
}

Soldier::Soldier(const char* name, size_t age, size_t combat, size_t salary)
{
    setName(name);
    setAge(age);
    setCombatSkills(combat);
    setSalary(salary);
}

Soldier::Soldier(const Soldier& other)
{
    copyFrom(other);
}

Soldier& Soldier::operator=(const Soldier& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Soldier::~Soldier()
{
    free();
}

const char* Soldier::getName() const
{
    return name;
}

size_t Soldier::getAge() const
{
    return age;
}

size_t Soldier::getCombatSkills() const
{
    return combatSkills;
}

size_t Soldier::getSalary() const
{
    return salary;
}

void Soldier::setName(const char* newName)
{
    if (!newName) return;
    free();
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void Soldier::setAge(size_t newAge)
{
    age = newAge;
}

void Soldier::setCombatSkills(size_t newSkills)
{
    combatSkills = newSkills;
}

void Soldier::setSalary(size_t newSalary)
{
    salary = newSalary;
}

void Soldier::print() const
{
    std::cout << "Name: " << name
        << ", Age: " << age
        << ", Skills: " << combatSkills
        << ", Salary: " << salary << std::endl;
}
