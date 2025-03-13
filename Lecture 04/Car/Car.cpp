#include "Car.h"

Car::Car()
{
    year = 0;
    maxSpeed = 200;
    name = nullptr;
    countOfKm = 0;
    km =nullptr;
}

Car::Car(size_t _year, unsigned int _maxSpeed, const char* _name, const unsigned int* _km, size_t _countOfKm)
{
    year = _year;
    maxSpeed = _maxSpeed;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    km = new unsigned int[_countOfKm];
    for (int i = 0; i < _countOfKm; ++i)
    {
        km[i] = _km[i];
    }
    countOfKm = _countOfKm;
}

void Car::writeToFile(std::ofstream& ofs)const
{
    if (!ofs.is_open())
    {
        throw("error!");
    }
    ofs.write((const char*)&year, sizeof(year));
    ofs.write((const char*)&maxSpeed, sizeof(maxSpeed));

    size_t nameLen = strlen(name) + 1;
    ofs.write((const char*)&nameLen, sizeof(nameLen));
    ofs.write(name, nameLen);

    ofs.write((const char*)&countOfKm, sizeof(countOfKm));
    ofs.write((const char*)km, countOfKm * sizeof(unsigned int));

}

 void Car:: readFromFile(std::ifstream& ifs)
{
    if (!ifs.is_open())
    {
        throw("error!");
    }
    ifs.read((char*)&year, sizeof(year));
    ifs.read((char*)&maxSpeed, sizeof(maxSpeed));

    size_t nameLen;
    ifs.read((char*)&nameLen, sizeof(nameLen));
    delete[]name; // ann0
    name = new char[nameLen + 1];
    ifs.read(name, nameLen);
    name[nameLen] = '\0';

    ifs.read((char*)&countOfKm, sizeof(countOfKm));
    ifs.read((char*)km, countOfKm * sizeof(unsigned int));

}

unsigned int Car::howManyKm()const
{
    unsigned int sumOfKm = 0;
    for (int i = 0; i < countOfKm; i++)
    {
        sumOfKm += km[i];
    }
    return sumOfKm;
}

unsigned int Car::theLongestRide()const
{
    if (countOfKm == 0)
    {
        return 0;
    }

    unsigned int longestRide=km[0];
    for (int i = 1; i < countOfKm; i++)
    {
        if (km[i] > longestRide)
        {
            longestRide = km[i];
       }
    }
    return longestRide;
}

Car::~Car()
{
    delete[]name;
    name = nullptr;
    delete[]km;
    km = nullptr;
}
