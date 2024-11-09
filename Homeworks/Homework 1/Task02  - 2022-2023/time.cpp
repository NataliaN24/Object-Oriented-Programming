#include<iostream>
#include<fstream>
#include"time.h"
//the code of time.h and time.cpp is from github of A.Dimitriev ->week 5
Time::Time() :Time(0, 0, 0) {}
Time::Time(size_t hours, size_t mins, size_t seconds) {
	setHours(hours);
	setMins(mins);
	setSeconds(seconds);
}

size_t Time::getSeconds() const {
	return seconds;

}
size_t Time::getMins() const {
	return mins;

}
size_t Time::getHours() const {
	return hours;

}

void Time::setSeconds(size_t seconds) {
	if (seconds > 59)
		seconds = 59;
	this->seconds = seconds;

}
void Time::setMins(size_t mins) {
	if (mins > 59)
		mins = 59;
	this->mins = mins;

}
void Time::setHours(size_t hours) {
	if (hours > 23)
		hours = 23;
	this->hours = hours;

}

void Time::print() const
{
	std::cout << getHours() << ":" << getMins() << ":" << getSeconds() <<std:: endl;
}