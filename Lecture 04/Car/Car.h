#pragma once
#include <iostream>
#include <sstream>
#include<fstream>
#pragma warning(disable:4996)

//Създайте структура Car, която съдържа в себе си име на марка с произволна дължина, година на създаване, 
//максимална скорост и масив с произволна дължина, пазещ колко километра са били пътуванията на колата(цяло число).Трябва да имплементирате :
//
//Дефолтен конструктор
//Конструктор с параметрите на колата
//Деструктор(за да освободите динамичната памет, когато обектът умре)
//Функция за записване на колата във файл
//Функция, която прочита данни от файл
//Функция, която връща колко общо са изминатите километри на автомобила
//Функция, която връща големината на най - дългото пътуване

class Car
{
	size_t year;
	unsigned int maxSpeed;
	char* name;
	unsigned int* km;
	size_t countOfKm;
public:
	Car();
	Car(size_t _year, unsigned int _maxSpeed, const char* _name, const unsigned int* _km,size_t _countOfKm);
	void writeToFile(std::ofstream&ofs)const;
	void readFromFile(std::ifstream&ifs);
	unsigned int howManyKm()const;
	unsigned int theLongestRide()const;
	~Car();

};

