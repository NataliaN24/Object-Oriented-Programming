#include <iostream>
#include <fstream>
#include <cstring>

#pragma warning( disable : 4996)

struct Student
{
	char* name;
	int age;
	int fn;
};

Student initialize(const char* name, int age, int fn)
{
	Student st;
	st.name = new char[strlen(name) + 1];
	strcpy(st.name, name);
	st.age = age;
	st.fn = fn;
	return st;
}

void free(Student&st)
{
	delete[]st.name;
	st.fn = 0;
	st.age = 0;
}

void saveToBinary(std::ofstream& ofs, const Student& st)
{
	int length = strlen(st.name);
	ofs.write((const char*)&length, sizeof(int));
	ofs.write(st.name, length);

	ofs.write((const char*)&st.age, sizeof(st.age));
	ofs.write((const char*)&st.fn, sizeof(st.fn));
}

Student readFromBinary(std::ifstream& ifs)
{
	Student st;

	int length;
	ifs.read((char*)&length, sizeof(length));
	st.name = new char[length + 1];
	ifs.read(st.name, length);
	st.name[length] = '\0';
	ifs.read((char*)&st.age, sizeof(st.age));
	ifs.read((char*)&st.fn, sizeof(st.fn));

	return st;
}

void print(const Student& st)
{
	std::cout << st.name << " " << st.age << " " << st.fn << std::endl;
}

void saveArrayToFile(std::ofstream& ofs, const Student* arr,size_t size)
{
	ofs.write((const char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		saveToBinary(ofs, arr[i]);
	}
}

void readArrayFromFile(std::ifstream& ifs, Student*& arr, size_t& size)
{
	ifs.read((char*)&size, sizeof(size));
	arr = new Student[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = readFromBinary(ifs);
	}
}

int main()
{
	Student students[] = {
		initialize("Alice", 20, 12345),
		initialize("Bob", 22, 23456),
		initialize("Charlie", 21, 34567)
	};

	size_t size = sizeof(students) / sizeof(students[0]);

	std::ofstream outFile("students.bin", std::ios::binary);
	if (outFile.is_open())
	{
		saveArrayToFile(outFile, students, size);
		outFile.close();
	}

	for (size_t i = 0; i < size; ++i)
	{
		free(students[i]);
	}

	Student* loadedStudents = nullptr;
	size_t loadedSize = 0;

	std::ifstream inFile("students.bin", std::ios::binary);
	if (inFile.is_open())
	{
		readArrayFromFile(inFile, loadedStudents, loadedSize);
		inFile.close();
	}

	for (size_t i = 0; i < loadedSize; ++i)
	{
		print(loadedStudents[i]);
		free(loadedStudents[i]);
	}

	delete[] loadedStudents;

	return 0;
}