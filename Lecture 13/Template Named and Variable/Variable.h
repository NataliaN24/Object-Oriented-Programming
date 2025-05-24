#pragma once
#include"Named.hpp"

class Variable:public Named<int>
{
public:
	Variable() = default;
	Variable(const char* name, int data);
	int operator*()const;
	Variable& operator=(const Variable& right);



};
bool operator==(const Variable& left, const Variable& right);
bool operator!=(const Variable& left, const Variable& right);

