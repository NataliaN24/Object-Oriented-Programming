#include <iostream>
#pragma warning  (disable:4996)
#include <cstring>
#include<cassert>
#include <fstream>
constexpr char filename1[] = "district.txt";
constexpr char filename2[] = "sorted.txt";
constexpr int maxLenCity = 63;
constexpr int maxLenDistrict = 20;

//Създайте структура City, която описва град и има име(до 63 символа) и брой жители.
//Създайте и структура District, която съдържа в себе си до 20 града и пази текущия си размер.
//
//Напишете функция, която записва във файл една област.
//Напишете друга функция, която прочита област от файл, след което сортира градовете в областта
//според броя на жителите им във възходящ ред и записва резултата в друг файл.

struct City
{
	char name[maxLenCity + 1];
	size_t populationNumber;
};

struct District
{
	City cities[maxLenDistrict];
	size_t count;
};

void writeCityToFile(std::ofstream &ofs,const City& c)
{
	ofs << c.name << " " << c.populationNumber;
}

void readCityFromFile(std::ifstream& ifs, City& c)
{
	ifs >> c.name >> c.populationNumber;
}

void writeToFile(const District& d,const char*name)
{
	std::ofstream ofs(name);
	if (!ofs.is_open())
	{
		throw("Error!");
	}
	ofs << d.count;
	for (int i = 0; i < d.count; i++)
	{
		writeCityToFile(ofs, d.cities[i]);
	}
}
void sortCities(District& d, const char* name)
{

	for (int i = 0; i < d.count - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < d.count; j++)
		{
			if (d.cities[j].populationNumber < d.cities[i].populationNumber)
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(d.cities[i].name, d.cities[minIndex].name);
			std::swap(d.cities[i].populationNumber, d.cities[minIndex].populationNumber);
		}
	}
	writeToFile(d, name);
}


void readFromFile( District& d,const char*name1,const char*name2)
{
	std::ifstream ifs(name1);
	if (!ifs.is_open())
	{
		throw("Error!");
	}
	ifs >> d.count;
	for (int i = 0; i < d.count; i++)
	{
		readCityFromFile(ifs, d.cities[i]);
	}
	sortCities(d, name2);
}


int main()
{
	try
	{
		District district;


		district.count = 3;
		strcpy(district.cities[0].name, "CityA");
		district.cities[0].populationNumber = 10000;

		strcpy(district.cities[1].name, "CityB");
		district.cities[1].populationNumber = 5000;

		strcpy(district.cities[2].name, "CityC");
		district.cities[2].populationNumber = 20000;

		writeToFile(district, filename1);

		readFromFile(district,filename1,filename2);

		std::cout << "Cities sorted and written to " << filename2 << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
	}

	return 0;
	
}
