#include <iostream>
#include<cassert>
#include<fstream>

constexpr int  STUDENT_MAX_SIZE = 10;
constexpr int NAME_MAX = 100;

enum class Major
{
	inf,
	cs,
	s,
	unknown

};

enum class Criteria
{
	byName,
	byMajor,
	byFn
};
const char* getMajor(Major m)
{
	switch (m)
	{
	case Major::inf: return "Informatics";
	case Major::cs:return "Computer Science";
	case Major::s:return "Software Engineering";
	}
	return " ";
}

struct Student
{
	char name[NAME_MAX] = " ";
	unsigned fn = 0;
	Major major = Major::unknown;
};

void printStudent(const Student& st)
{
	std::cout << st.name << " " << st.fn << " " << getMajor(st.major) << std::endl;
}

struct StudentDatabase
{
	Student students[STUDENT_MAX_SIZE];
	unsigned count = 0;
};

void sortStudents(StudentDatabase& database)
{
	assert(database.count <= STUDENT_MAX_SIZE);
}

void printDatabase(const StudentDatabase& db)
{
	assert(db.count <= STUDENT_MAX_SIZE);
	for (int i = 0; i < db.count; i++)
	{
		printStudent(db.students[i]);
	}
}

void sortDatabase(StudentDatabase& db, bool(*isLess)(const Student& lhs, const Student& rhs))
{
	for (int i = 0; i < db.count - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < db.count; j++)
		{
			if (isLess(db.students[j], db.students[minIndex]))
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(db.students[i], db.students[minIndex]);
		}
	}
}

void sortByCriteria(StudentDatabase& db, Criteria cr)
{
	switch (cr)
	{
	case Criteria::byName:return sortDatabase(db, [](const Student& lhs, const Student& rhs) {return strcmp(lhs.name, rhs.name) < 0; });
	case Criteria::byMajor:return sortDatabase(db, [](const Student& lhs, const Student& rhs) {return lhs.major < rhs.major; });
	case Criteria::byFn:return sortDatabase(db, [](const Student& lhs, const Student& rhs) {return lhs.fn < rhs.fn; });

	}

}

void serializeStudent(std::ostream& os, const Student& st)
{
	os << st.name << std::endl << st.fn << std::endl << (int)st.major << std::endl;
}

void serializeDatabase(std::ostream& os, const StudentDatabase& db)
{
	os << db.count << std::endl;
	for (int i = 0; i < db.count; ++i)
	{
		serializeStudent(os, db.students[i]);
	}
}

void deserializeStudent(std::istream& ifs, Student& st)
{
	ifs.ignore();
	ifs.getline(st.name, NAME_MAX);
	ifs >> st.fn;
	int tempMajor;
	ifs >> tempMajor;
	st.major = (Major)tempMajor;

}

StudentDatabase deserializeStudentDatabase(std::istream& ifs)
{
	StudentDatabase st;
	ifs >> st.count;
	for (int i = 0; i < st.count; ++i)
	{
		deserializeStudent(ifs, st.students[i]);
	}
	return st;
}

int main()
{
	StudentDatabase db;

	Student st1 = { "Alice", 12345, Major::cs };
	Student st2 = { "Bob", 23456, Major::inf };
	Student st3 = { "Charlie", 34567, Major::s };

	db.students[db.count++] = st1;
	db.students[db.count++] = st2;
	db.students[db.count++] = st3;

	std::ofstream outFile("students.dat");
	if (outFile.is_open())
	{
		serializeDatabase(outFile, db);
		outFile.close();
	}
	else
	{
		std::cerr << "Unable to open file for writing." << std::endl;
	}

	StudentDatabase newDb;
	std::ifstream inFile("students.dat");
	if (inFile.is_open())
	{
		newDb = deserializeStudentDatabase(inFile);
		inFile.close();
	}
	else
	{
		std::cerr << "Unable to open file for reading." << std::endl;
	}

	std::cout << "Deserialized database:" << std::endl;
	printDatabase(newDb);

	return 0;
}