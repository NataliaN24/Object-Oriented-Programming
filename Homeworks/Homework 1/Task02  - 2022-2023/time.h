#pragma once
#include<iostream>
//the code of time.h and time.cpp is from github of A.Dimitriev ->week 5
class Time {
	size_t seconds; 
	size_t mins; 
	size_t hours;
public:
	Time(); 
	Time(size_t hours, size_t mins, size_t seconds);
	size_t getSeconds() const;
	size_t getMins() const;
	size_t getHours() const;

	void setSeconds(size_t seconds);
	void setMins(size_t mins);
	void setHours(size_t hours);
	void print() const;


};
