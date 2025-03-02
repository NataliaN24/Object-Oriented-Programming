#include <iostream>
#pragma warning  (disable:4996)
#include <cstring>
#include<cassert>
#include <fstream>
constexpr char filename[] = "result1.txt";
//Да се напише функция, която чете от конзолата 2 числа и записва във файл с име result1.txt сумата и разликата им.Да се 
//напише функция, която
//чете от файла result1.txt сумата и разликата на двете числа и отпечатва на конзолата кои са били оригиналните числа


void writeToFile(int sum,int difference)
{
	std::ofstream ofs(filename, std::ios::out);
	if (!ofs.is_open())
	{
		throw("error opening the file! ");
	}
	ofs << sum << " " << difference;
}

void readFromFile()
{
	std::ifstream ifs(filename, std::ios::in);
	if (!ifs.is_open())
	{
		throw("error opening the file! ");
	}
	int sum = 0;
	int difference = 0;
	ifs >> sum >> difference;
	
	std::cout << "sum:" << sum << " " <<"difference:" << difference << std::endl;
	int a = 0;
	int b = 0;
	b = (sum - difference) / 2;
	a = sum - b;
	std::cout <<"a:" << a << " "<<"b:" << b;
}

void readNumbers(int& a, int& b)
{
	std::cin >> a >> b;
	int sum = a + b;
	int difference =  a - b;
	writeToFile(sum, difference);
}

int main()
{
	int a=0, b=0;
	readNumbers(a,b);
	readFromFile();
}
