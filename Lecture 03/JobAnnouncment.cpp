#include <iostream>
#pragma warning  (disable:4996)
#include <cstring>
#include<fstream>

//Създайте структура, описваща обява за работа, която се характеризира с :
//
//Име на фирмата(с дължина не повече от 20).
//Брой на програмистите във фирмата
//Заплата(long long)
//Създайте функция, която прочита n на брой обяви от стандартния вход.Обявите се запазват в двоичен файл, като ако във файла вече има информация, тя не се изтрива.
//
//Създайте функция void filterOffers(const char* filePath, long long minSalary), която приема име на файл, от който четем обявите и минимална заплата и всички валидни обяви биват запазвани в отделен бинарен файл.
//
//Създайте функция, bool existOffer(const char* filePath, const char* name), която проверява дали дадена фирма фигурира в подадения файл.

constexpr int MAX_NAME_LENGTH = 20;

struct JobAnnouncment
{
	char name[MAX_NAME_LENGTH + 1] = " ";
	int programmers;
	long long salary;
};

JobAnnouncment*readAnnouncments(int &n )
{
	std::cin >> n;
	std::cin.ignore();

	JobAnnouncment* announcments = new JobAnnouncment[n];

	for (int i = 0; i < n; i++)
	{
		std::cin.getline(announcments->name, MAX_NAME_LENGTH+1);
		std::cin >> announcments->programmers >> announcments->salary;
		std::cin.ignore();
	}
	return announcments;
}

size_t getFileSize(std::ifstream& ifs)
{
	size_t currentPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currentPos);
	return size;
}

void saveArrayToFile(const char* filename, const JobAnnouncment* arr,int count) {
	std::ofstream ofs(filename, std::ios::binary | std::ios::app); 
	if (!ofs) {
		std::cerr << "Error opening file for writing.\n";
		return;
	}
	ofs.write((const char*)arr, count * sizeof(JobAnnouncment));
}

JobAnnouncment* readArrayFromFile(std::ifstream& ifs,int &arrSize)
{
	size_t sizeInBytes = getFileSize(ifs);
	 arrSize = sizeInBytes / sizeof(JobAnnouncment);
	JobAnnouncment* arr = new JobAnnouncment[arrSize];
	ifs.seekg(0);
	ifs.read((char*)arr,sizeInBytes );
	return arr;
}

void filterOffers(const char* filePath, long long minSalary)
{
	std::ifstream ifs(filePath, std::ios::binary);
	if (!ifs.is_open())
	{
		std::cerr << "error opening the file!";
		return;
	}

	int arrSize = 0;
	JobAnnouncment* arr = readArrayFromFile(ifs, arrSize);
	ifs.close();

	std::ofstream ofs("outputFile.bin", std::ios::binary);
	if (!ofs.is_open())
	{
		std::cerr << "error opening the file!";
		delete[] arr;
		return;
	}

	std::cout << "Offers with salary >= " << minSalary << ":\n";
	bool found = false;

	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i].salary >= minSalary)
		{
			ofs.write((const char*)&arr[i], sizeof(JobAnnouncment));

			std::cout << "Company: " << arr[i].name
				<< ", Programmers: " << arr[i].programmers
				<< ", Salary: " << arr[i].salary << "\n";

			found = true;
		}
	}

	if (!found)
	{
		std::cout << "No offers matched the criteria.\n";
	}

	delete[] arr;
	ofs.close();
}


bool existOffer(const char* filePath, const char* name)
{
	std::ifstream ifs(filePath, std::ios::binary);
	if (!ifs.is_open())
	{
		std::cerr << "error opening the file!";
	}
	int arrSize = 0;
	JobAnnouncment* announcments = readArrayFromFile(ifs, arrSize);
	
	for (int i = 0; i < arrSize; i++)
	{
		if (strcmp(announcments[i].name, name) == 0)
		{
			delete[]announcments;
			return true;
		}
	}
	delete[]announcments;
	return false;
}

int main() {
	
	JobAnnouncment offers[3] = {
		{"Google", 150, 6000},
		{"Facebook", 100, 4500},
		{"StartupX", 20, 2000}
	};


	saveArrayToFile("jobOffers.bin", offers, 3);
	

	filterOffers("jobOffers.bin", 3000);

	if (existOffer("jobOffers.bin", "Google")) {
		std::cout << "Offer from Google exists.\n";
	}
	else {
		std::cout << "No offer from Google.\n";
	}

	if (existOffer("jobOffers.bin", "Tesla")) {
		std::cout << "Offer from Tesla exists.\n";
	}
	else {
		std::cout << "No offer from Tesla.\n";
	}

	return 0;
}
