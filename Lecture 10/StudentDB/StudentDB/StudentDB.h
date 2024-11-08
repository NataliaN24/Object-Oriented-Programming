#pragma once
#include"Student.h"

class StudentDB
{
protected:
	Student* students;
	unsigned capacity;
	unsigned size;
private:
	void copyFrom(const StudentDB& other);
	void moveFrom(StudentDB&& other);
	void free();
	void resize(unsigned newCap);
public:
	StudentDB();
	StudentDB(const StudentDB& other);
	StudentDB(StudentDB&& other)noexcept;
	StudentDB& operator=(const StudentDB& other);
	StudentDB& operator=(StudentDB&& other)noexcept;
	~StudentDB();

	bool add(const Student& st);
	bool remove(unsigned fn);
	bool find(unsigned fn);
	void display()const;
};

