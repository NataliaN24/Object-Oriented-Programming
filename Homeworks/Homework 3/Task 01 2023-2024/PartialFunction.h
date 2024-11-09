#pragma once
#include<iostream>

class PartialFunction
{
public:
	virtual int32_t calculateTheResult(int32_t x)const = 0;
	virtual bool IsDefinedAtPoint(int32_t x)const = 0;
	virtual ~PartialFunction() = default;
	virtual PartialFunction* clone()const = 0;
	virtual int32_t operator()(int32_t x)const = 0;
};