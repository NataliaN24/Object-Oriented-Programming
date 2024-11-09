#include "MinimumOfPartialFunctions.h"

MinimumOfPartialFunctions::MinimumOfPartialFunctions(PartialFunction** functions, int count) : functions(functions), count(count)
{
}

bool MinimumOfPartialFunctions::IsDefinedAtPoint(int32_t x) const
{
	for (int i = 0; i < count; ++i)
	{
		if (!functions[i]->IsDefinedAtPoint(x))
		{
			return false;
		}
	}
	return true;
}

int32_t MinimumOfPartialFunctions::calculateTheResult(int32_t x) const
{
	if (!IsDefinedAtPoint(x)) 
	{
		throw std::out_of_range("Error.Not defined function!");
	}

	int32_t minResult = functions[0]->calculateTheResult(x);

	for (int i = 1; i < count; ++i)
	{
		int32_t result = functions[i]->calculateTheResult(x);
		if (result < minResult) 
		{
			minResult = result;
		}
	}
	return minResult;
}

PartialFunction* MinimumOfPartialFunctions::clone() const
{
	return new MinimumOfPartialFunctions(*this);
}

int32_t MinimumOfPartialFunctions::operator()(int32_t x) const
{
	return calculateTheResult(x);
}

MinimumOfPartialFunctions::MinimumOfPartialFunctions() :functions(nullptr), count(0)
{
}

MinimumOfPartialFunctions::MinimumOfPartialFunctions(const MinimumOfPartialFunctions& other)
{
	copyFrom(other);
}

MinimumOfPartialFunctions::MinimumOfPartialFunctions(MinimumOfPartialFunctions&& other)noexcept
{
	moveFrom(std::move(other));
}

MinimumOfPartialFunctions& MinimumOfPartialFunctions::operator=(const MinimumOfPartialFunctions& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MinimumOfPartialFunctions& MinimumOfPartialFunctions::operator=(MinimumOfPartialFunctions&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MinimumOfPartialFunctions::~MinimumOfPartialFunctions()
{
	free();
}

void MinimumOfPartialFunctions::copyFrom(const MinimumOfPartialFunctions& other)
{
	count = other.count;
	functions = new PartialFunction * [count];

	for (int i = 0; i < count; ++i)
	{
		functions[i] = other.functions[i]->clone();
	}
}

void MinimumOfPartialFunctions::moveFrom(MinimumOfPartialFunctions&& other)noexcept
{
	count = other.count;
	functions = other.functions;

	other.count = 0;
	other.functions = nullptr;
}

void MinimumOfPartialFunctions::free()
{
	for (int i = 0; i < count; ++i)
	{
		delete functions[i];
	}

	delete[] functions;
	functions = nullptr;
	count = 0;
}