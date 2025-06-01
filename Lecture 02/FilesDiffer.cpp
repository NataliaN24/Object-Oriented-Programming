#include <iostream>
#pragma warning  (disable:4996)
#include <cstring>
#include<cassert>
#include <fstream>
constexpr char filename1[] = "input1.txt";
constexpr char filename2[] = "input2.txt";
//Напишете програма, която отваря два текстови файла и сравнява 
//техните съдържания, извеждайки на екрана първия ред, на който двата файла се различават.

void compare(std::ifstream& ifs1, std::ifstream& ifs2)
{
	char ch1;
	char ch2;
	int line = 1;
	while (true)
	{
		ch1 = ifs1.get();
		ch2 = ifs2.get();

		if ((ch1 == EOF && ch2 != EOF) || (ch1 != EOF && ch2 == EOF))
		{
			std::cout << "File differ at line "<<line;
			break;
		}
		else if (ch1 != ch2)
		{
			std::cout << "Files differ at line:"<<line<<"file1:" << ch1 << " "<<"file2:" << ch2;
			break;
		}
		else if (ch1 == EOF && ch2 == EOF)
		{
			std::cout << "Files are identical";
		}
		if (ch1 == '\n')
		{
			line++;
		}
	}
}

int main()
{
	std::ifstream ifs1(filename1);
	std::ifstream ifs2(filename2);
	if (!ifs1.is_open()||!ifs2.is_open())
	{
		throw ("Error!");
	}
	compare(ifs1, ifs2);
	
}

//second solution

#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    std::ifstream ifs1("file1.txt");
    std::ifstream ifs2("file2.txt");

    if (!ifs1 || !ifs2) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    char buff1[1024];
    char buff2[1024];
    int line = 1;

    while (ifs1.getline(buff1, 1024) && ifs2.getline(buff2, 1024)) {
        if (strcmp(buff1, buff2) != 0) {
            std::cout << "Difference at line " << line << ":" << std::endl;
            std::cout << buff1 << std::endl;
            break;
        }
        ++line;
    }

    if ((ifs1 && !ifs2) || (!ifs1 && ifs2)) {
        std::cout << "Files differ in length at line " << line << "." << std::endl;
    }

    return 0;
}

