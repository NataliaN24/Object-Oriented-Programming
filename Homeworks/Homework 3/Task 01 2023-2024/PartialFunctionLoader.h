#pragma once
#include"MaximumOfPartialFunctions.h"
#include"MinimumOfPartialFunctions.h"
#include"PartialFunctionByCriteria.hpp"
#include"BaseCase.h"
#include"Case0.h"
#include"Case1.h"
#include"Case2.h"
#include<fstream>
#include<cstring>

class PartialFunctionLoader
{
public:

	PartialFunction* loadFunction(const char* filename);

private:

	PartialFunction* handleCase0(std::ifstream& file, uint16_t N);
	PartialFunction* handleCase1(std::ifstream& file, uint16_t N);
	PartialFunction* handleCase2(std::ifstream& file, uint16_t N);
	PartialFunction* handleCase3(std::ifstream& file, uint16_t N);
	PartialFunction* handleCase4(std::ifstream& file, uint16_t N);
};