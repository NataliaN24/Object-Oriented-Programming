#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

bool isSmallLetter(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isUpperLetter(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool onlySmallLetters(const char* str)
{
	size_t length = strlen(str);
	for (size_t i = 0; i < length; ++i)
	{
		if (!isSmallLetter(str[i]))
		{
			return false;
		}
	}
	return true;
}

constexpr int NAME_MAX_LENGTH = 20;
constexpr int NAME_MIN_LENGTH = 2;
constexpr int AGE_MIN = 5;
constexpr int AGE_MAX = 90;

class Student
{
	char name[NAME_MAX_LENGTH + 1] = "Unknown";
	int age = AGE_MIN;
	
	bool isValidAge(int age)
	{
		return age >= AGE_MIN && age <= AGE_MAX;
	}
	bool isValidName(const char* name)
	{
		if (name == nullptr)
		{
			return false;
		}
		size_t len = strlen(name);
		if (len <= NAME_MIN_LENGTH || len >= NAME_MAX_LENGTH)
		{
			return false;
		}
		if (!isUpperLetter(*name))
		{
			return false;
		}
		return onlySmallLetters(name + 1);
	}
public:
	Student() = default;

	Student(const char* name, int age)
	{
		setName(name);
		setAge(age);
	}

	int getAge()const
	{
		return age;
	}

	const char* getName()const
	{
		return name;
	}

	void setName(const char* name)
	{
		if (isValidName(name))
		{
			strcpy(this->name, name);
		}
		else
		{
			strcpy(this->name, "Unknown");
		}
	}

	void setAge(int age)
	{
		if (isValidAge(age))
		{
			this->age = age;
		}
		else
		{
			this->age = 15;
		}
	}
};

int main() {
	Student st("Natalia", 21);
	std::cout << st.getName() << " " << st.getAge();
}