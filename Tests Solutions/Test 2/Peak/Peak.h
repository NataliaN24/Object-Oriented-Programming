#pragma once
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)

class MPeak;
class TPeak;

class Peak
{
	char* nameMountain;
	double height;

	void copyFrom(const Peak& other);
	void free();

public:
	Peak();
	Peak(const char* name, double height);
	Peak(const Peak& other);
	Peak& operator=(const Peak& other);
	virtual void printPeakName()const=0;
	virtual~Peak();

	const char* getName()const;
	double getHeight()const;

	void setName(const char* newName);
	void setHeight(double h);

	virtual Peak* clone()const=0;

	virtual bool twoPeaksNear(const Peak* other)const=0;

	virtual bool nearMpeak(const MPeak* mpeak)const = 0;
	virtual bool nearTPeak(const TPeak* tpeak)const=0;


};
