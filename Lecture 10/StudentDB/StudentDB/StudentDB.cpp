#include "StudentDB.h"

void StudentDB::copyFrom(const StudentDB& other)
{
    size = other.size;
    capacity = other.capacity;
    students = new Student[capacity];
    for (int i = 0; i < size; i++)
    {
        students[i] = other.students[i];
    }
}

void StudentDB::moveFrom(StudentDB&& other)
{
    size = other.size;
    capacity = other.capacity;
    students = other.students;

    other.size = 0;
    other.capacity = 0;
    other.students = nullptr;
}

void StudentDB::free()
{
    delete[]students;
}

void StudentDB::resize(unsigned newCap)
{
    capacity = newCap;
    Student*st= new Student[capacity];
    for (int i = 0; i < size; i++)
    {
        st[i] = students[i];
    }
    delete[]students;
    students = st;

}

StudentDB::StudentDB()
{
    capacity = 10;
    size = 0;
    students = new Student[capacity];

}

StudentDB::StudentDB(const StudentDB& other)
{
    copyFrom(other);
}

StudentDB::StudentDB(StudentDB&& other) noexcept
{
    moveFrom(std::move(other));
}

StudentDB& StudentDB::operator=(const StudentDB& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

StudentDB& StudentDB::operator=(StudentDB&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

StudentDB::~StudentDB()
{
    free();
}

bool StudentDB::add(const Student& st)
{
    if (size == capacity) {
        resize(capacity*2);
    }
    students[size++] = st;
    return true;
}

bool StudentDB::remove(unsigned fn)
{
    for (int i = 0; i < size; i++)
    {
        if (students[i].getFn() == fn)
        {
            std::swap(students[i], students[size - 1]);
            size--;
            return true;
        }
    }
    return false;
}

bool StudentDB::find(unsigned fn)
{
    for (int i = 0; i < size; i++)
    {
        if (students[i].getFn() == fn)
        {
            return true;
        }
    }
    return false;
}

void StudentDB::display() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << students[i].getName() << " " << students[i].getFn() << " " << students[i].getCourse() << std::endl;
    }
}
