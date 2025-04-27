#include "Classroom.h"

void Classroom::copyFrom(const Classroom& other)
{
    capacity = other.capacity;
    count = other.count;
    students = new Student * [capacity];
    for (int i = 0; i < capacity; i++)
    {
        students[i] = new Student(*other.students[i]);
    }
}

void Classroom::free()
{
    for (int i = 0; i < count; i++)
    {
        delete students[i];
    }
    delete[]students;
}

void Classroom::moveFrom(Classroom&& other)
{
    capacity = other.capacity;
    count = other.count;
    students = other.students;

    other.capacity = 0;
    other.count = 0;
    other.students = nullptr;
}

void Classroom::resize(int newCap)
{
    Student** copyClass = new Student * [newCap];
    for (int i = 0; i < count; i++)
    {
        copyClass[i] = students[i];
    }
    delete[]students;
    students = copyClass;
    capacity = newCap;
}

Classroom::Classroom()
{
    capacity = MaxStudentsInClass;
    students = new Student * [capacity]{nullptr};
    count = 0;
}

Classroom::Classroom(int cap)
{
    students = new Student * [cap]{nullptr};
    capacity = cap;
}

Classroom::Classroom(const Classroom& other)
{
    copyFrom(other);
}

Classroom::Classroom(Classroom&& other)
{
    moveFrom(std::move(other));
}

Classroom& Classroom::operator=(const Classroom& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Classroom& Classroom::operator=(Classroom&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Classroom::~Classroom()
{
    free();
}

void Classroom::dropStudent(int index)
{
    if (index < 0 || index >= capacity || students[index] == nullptr)
    {
        throw(std::out_of_range("No such index exits!"));
    }
    delete students[index];
    students[index] = nullptr;
    count--;
}

int Classroom::howManyFreeSeats() const
{
    int freeSeats = 0;
    for (int i = 0; i < capacity; i++)
    {
        if (students[i] == nullptr)
        {
            freeSeats++;
        }
    }
    return freeSeats;
}

int Classroom::getEmptiestRow(int rowSize,int RowCount)//rowSize=how many seats are in a row   rowCount=how many seats are in general
{
    int minStudents = INT32_MAX;
    int emptyRow = 0;
    for (int row = 0; row < RowCount; row++)
    {
        int currentRowStudents = 0;
        for (int j = 0; j < rowSize; j++)
        {
            int index = row * rowSize + j;
            if (index < capacity && students[index] != nullptr)
            {
                currentRowStudents++;
            }
        }
        if (currentRowStudents < minStudents)
        {
            minStudents = currentRowStudents;
            emptyRow = row;
        }
    }
    return emptyRow;
    
}

void Classroom::swapStudents(int index1, int index2)
{
    if (index1 < 0 || index2 < 0 || index1 >= capacity || index2 >= capacity)
        throw std::out_of_range("Invalid index!");

    std::swap(students[index1], students[index2]);
}

void Classroom::addStudent(int index, const Student& st)
{
    if (index < 0 || index >= capacity)
        throw std::out_of_range("Invalid index!");

    if (students[index] != nullptr)
        throw std::logic_error("Seat already taken!");

    students[index] = new Student(st);
    count++;

}
void Classroom::addStudent(int index,Student&& st)
{
    if (index < 0 || index >= capacity)
        throw std::out_of_range("Invalid index!");

    if (students[index] != nullptr)
        throw std::logic_error("Seat already taken!");

    students[index] = new Student(std::move(st));
    count++;

}

int Classroom::getCount() const
{
    return count;
}

int Classroom::getCapacity() const
{
    return capacity;
}

void Classroom::print() const
{
    for (int i = 0; i < capacity; i++)
    {
        if (students[i] != nullptr) {
            std::cout << students[i]->getName() << students[i]->getFn() << std::endl;
        }
    }
}
