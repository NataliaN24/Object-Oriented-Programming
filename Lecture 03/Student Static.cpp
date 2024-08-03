#include <iostream>
#include <fstream>
#include <cstring>

#pragma warning(disable : 4996)
constexpr int SIZE = 30;

struct Student
{
    char name[SIZE];
    int age;
    int fn;
};

size_t getFileSize(std::ifstream& ifs)
{
    size_t currentPos = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t size = ifs.tellg();
    ifs.seekg(currentPos);
    return size;
}

void initialize(Student& st, const char* name, int age, int fn)
{
    strcpy(st.name, name);
    st.age = age;
    st.fn = fn;
}

void saveToBinary(std::ofstream& ofs, const Student* st, size_t count)
{
    ofs.write((const char*)st, count * sizeof(Student));
}

void readFromFile(Student*& arr, size_t& count, std::ifstream& ifs)
{
    size_t size = getFileSize(ifs);
    count = size / sizeof(Student);
    arr = new Student[count];
    ifs.read((char*)arr, size);
}

int main()
{
    Student students[] = {
        {"Alice", 20, 12345},
        {"Bob", 22, 23456},
        {"Charlie", 21, 34567}
    };

    size_t size = sizeof(students) / sizeof(students[0]);

    std::ofstream outFile("students.bin", std::ios::binary);
    if (outFile.is_open())
    {
        saveToBinary(outFile, students, size);
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
        return 1;
    }

    Student* loadedStudents = nullptr;
    size_t loadedSize = 0;

    std::ifstream inFile("students.bin", std::ios::binary);
    if (inFile.is_open())
    {
        readFromFile(loadedStudents, loadedSize, inFile);
        inFile.close();
    }
    else
    {
        std::cerr << "Unable to open file for reading." << std::endl;
        return 1;
    }

    for (size_t i = 0; i < loadedSize; ++i)
    {
        std::cout << loadedStudents[i].name << " " << loadedStudents[i].age << " " << loadedStudents[i].fn << std::endl;
    }

    delete[] loadedStudents;

    return 0;
}
