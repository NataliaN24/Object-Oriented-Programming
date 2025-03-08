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
        if (i % 16 == 15)
            std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < f.size; i++)
    {
        if (isValidSymbol(f.data[i]))
            std::cout << f.data[i] << "  ";
        else
            std::cout << ".  ";
        if (i % 16 == 15)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void changeByte(HexViewerFile& f, size_t index, unsigned char newValue)
{
    if (index < f.size)
    {
        f.data[index] = newValue;
        std::cout << "Operation successfully executed!" << std::endl;
    }
    else
    {
        std::cout << "Invalid index!" << std::endl;
    }
}

void removeLastByte(HexViewerFile& f)
{
    if (f.size > 0)
    {
        f.size--;
        std::cout << "Operation successfully executed!" << std::endl;
    }
    else
    {
        std::cout << "No bytes to remove!" << std::endl;
    }
}

void addByte(HexViewerFile& f, unsigned char value)
{
    unsigned char* newData = new unsigned char[f.size + 1];
    for (size_t i = 0; i < f.size; i++)
    {
        newData[i] = f.data[i];
    }
    newData[f.size] = value;

    delete[] f.data;
    f.data = newData;
    f.size++;

    std::cout << "Operation successfully executed!" << std::endl;
}

void save(const HexViewerFile& f, const char* filename)
{
    std::ofstream ofs(filename, std::ios::out | std::ios::binary);
    if (ofs.is_open())
    {
        ofs.write((const char*)f.data, f.size);
        ofs.close();
        std::cout << "File successfully saved!" << std::endl;
    }
    else
    {
        std::cout << "Error saving file!" << std::endl;
    }
}

void saveAs(const HexViewerFile& f, const char* filename)
{
    save(f, filename);
}

int main()
{
    const char* filename = "myData.dat";

    HexViewerFile file = initialize(filename);

    if (file.data == nullptr)
    {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::cout << "File loaded successfully! Size: " << file.size << " bytes" << std::endl;
    print(file);

    // Пример за промяна на байт по индекс
    changeByte(file, 1, 65);
    print(file);

    // Премахване на последния байт
    removeLastByte(file);
    print(file);

    // Добавяне на байт
    addByte(file, 66);
    print(file);

    // Запазване на промените
    save(file, "myData.dat");

    free(file);

    return 0;
}
