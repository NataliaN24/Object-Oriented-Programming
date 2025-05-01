#include "General.h"

void General::copyFrom(const General& other)
{
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);

    count = other.count;
    commanders = new Commander[count];
    for (size_t i = 0; i < count; ++i) {
        commanders[i] = other.commanders[i];
    }
}

void General::free()
{
    delete[] description;
    delete[] commanders;
    description = nullptr;
    commanders = nullptr;
    count = 0;
}

General::General():Soldier(), count(0)
{
    commanders = new Commander[count];
    description = new char[1];
    description[0] = '\0';
}

General::General(const char* name, size_t age, size_t combat, size_t salary, const char* description, const Commander* commanders, size_t count) :Soldier(name, age, combat, salary), count(count)
{
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);

    this->commanders = new Commander[count];
    for (size_t i = 0; i < count; ++i) {
        this->commanders[i] = commanders[i];
    }
}

General::General(const General& other)
{
    copyFrom(other);
}

General& General::operator=(const General& other)
{
    if (this != &other) {
        Soldier::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

General::~General()
{
    free();
}

void General::printArmy(std::ostream& os) const
{
    size_t totalSalary;
    size_t totalCombat;
    size_t totalSoldiers=0;
    os << "Army of general:" << getName() << '\n';//name of general
    totalSalary= getSalary();//totalSalary=salary of general+salary of each commander+salary of each soldier
    totalCombat = getCombatSkills();//= of general+ of each commander that general has +of each soldier that each commander has

    for (int i = 0; i < count; i++)//this is the count of commander
    {
        totalSalary += commanders[i].getSalary();
        totalCombat += commanders[i].getCombatSkills();
        totalSoldiers += commanders[i].getNumOfSoldiers();

        for (int j = 0; j < commanders[i].getNumOfSoldiers(); j++)
        {
            totalSalary += commanders[i].getBattalion()[j].getSalary();
            totalCombat += commanders[i].getBattalion()[j].getCombatSkills();
        }
    }
    size_t totalPeople = 1 + count + totalSoldiers;
    double avgStrength = totalPeople > 0 ? (double)totalCombat / totalPeople : 0.0;

    os << "Total maintenance cost: " << totalSalary << "\n";
    os << "Total army strength: " << totalCombat << "\n";
    os << "Average soldier strength: " << avgStrength << "\n";

}
