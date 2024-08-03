#include <iostream>
#include <fstream>
#include <iomanip>

struct HexViewerFile
{
	unsigned char* data;
	size_t size;
};

size_t getFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}

HexViewerFile initialize(const char* str)
{
	std::ifstream ifs(str, std::ios::in | std::ios::binary);
	HexViewerFile file;

	if (!ifs.is_open())
	{
		file.data = nullptr;
		file.size = 0;
		return file;
	}

	file.size = getFileSize(ifs);
	file.data = new unsigned char[file.size];
	ifs.read((char*)file.data, file.size);
	ifs.close();
	return file;
}

void free(HexViewerFile& file)
{
	delete[]file.data;
	file.size = 0;
}

bool isValidSymbol(unsigned char ch)
{
	return ch >= 'a' && ch <= 'z' ||
		ch >= 'A' && ch <= 'Z' ||
		ch >= '0' && ch <= '9';
}

void print(const HexViewerFile& f)
{
	for (int i = 0; i < f.size; i++)
	{
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)f.data[i] << " ";
		std::cout << std::endl;
		for (int i = 0; i < f.size; i++)
		{
			if (isValidSymbol(f.data[i]))
				std::cout << f.data[i] << "  ";
			else
				std::cout << ".. ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	const char* filename = "example.bin"; 

	HexViewerFile file = initialize(filename);

	if (file.data == nullptr)
	{
		std::cerr << "Failed to open the file." << std::endl;
		return 1;
	}

	print(file);

	free(file);

	return 0;
}