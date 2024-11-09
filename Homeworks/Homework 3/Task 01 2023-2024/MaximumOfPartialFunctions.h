#pragma once
#include"PartialFunction.h"

class MaximumOfPartialFunctions :public PartialFunction
{
public:

	MaximumOfPartialFunctions(PartialFunction** functions, int count);
	bool IsDefinedAtPoint(int32_t x) const override;
	int32_t calculateTheResult(int32_t x) const override;
	PartialFunction* clone()const override;
	int32_t operator()(int32_t x)const override;

private:

	PartialFunction** functions;
	int count;

	void copyFrom(const MaximumOfPartialFunctions& other);
	void moveFrom(MaximumOfPartialFunctions&& other)noexcept;
	void free();

public:

	MaximumOfPartialFunctions();
	MaximumOfPartialFunctions(const MaximumOfPartialFunctions& other);
	MaximumOfPartialFunctions(MaximumOfPartialFunctions&& other)noexcept;
	MaximumOfPartialFunctions& operator=(const MaximumOfPartialFunctions& other);
	MaximumOfPartialFunctions& operator=(MaximumOfPartialFunctions&& other)noexcept;
	~MaximumOfPartialFunctions();
};