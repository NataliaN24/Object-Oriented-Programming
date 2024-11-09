#include<iostream>
#include<fstream>
#include"date.h"

//the code of date.h and date.cpp is from github of A.Dimitriev ->week 5
Date::Date(): Date(0, 0, 0){ };
Date::Date(unsigned day, unsigned month, unsigned year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

unsigned Date::getDay() const
{
	return day;
}
unsigned Date::getMonth() const
{
	return month;
}
unsigned Date::getYear() const
{
	return year;
}

void Date::setYear(unsigned year)
{
	if (year == this->year)
		return;
	this->year = year;

	isModified = true;

}
void Date::setDay(unsigned day)
{
	if (day == this->day)
		return;

	if (day == 0 || day > MAX_DAYS[month - 1])
		day = 1;
	this->day = day;

	isModified = true;
}
void Date::setMonth(unsigned month)
{
	if (month == this->month)
		return;

	if (month == 0 || month > 12)
		month = 1;
	this->month = month;
	setDay(getDay());

	isModified = true;
}


void Date::print() const
{
	std::cout << day << "." << month << "." << year << std::endl;
}