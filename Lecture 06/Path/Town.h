#pragma once
#include<iostream>

class Town
{
	unsigned int id;
public:
	Town() = default;
	Town(unsigned int id);
	void setId(unsigned int ID);
	unsigned int getID()const;

};

