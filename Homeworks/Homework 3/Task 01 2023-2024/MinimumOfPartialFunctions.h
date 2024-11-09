#pragma once
#include"PartialFunction.h"

class MinimumOfPartialFunctions :public PartialFunction
{
public:

	MinimumOfPartialFunctions(PartialFunction** functions, int count);
	bool IsDefinedAtPoint(int32_t x) const override;
	int32_t calculateTheResult(int32_t x) const override;
	PartialFunction* clone()const override;
	int32_t operator()(int32_t x)const override;

private:

	PartialFunction** functions;
	int count;

	void copyFrom(const MinimumOfPartialFunctions& other);
	void moveFrom(MinimumOfPartialFunctions&& other)noexcept;
	void free();

public:

	MinimumOfPartialFunctions();
	MinimumOfPartialFunctions(const MinimumOfPartialFunctions& other);
	MinimumOfPartialFunctions(MinimumOfPartialFunctions&& other)noexcept;
	MinimumOfPartialFunctions& operator=(const MinimumOfPartialFunctions& other);
	MinimumOfPartialFunctions& operator=(MinimumOfPartialFunctions&& other)noexcept;
	~MinimumOfPartialFunctions();
};