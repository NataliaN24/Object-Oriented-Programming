#include "MaximumOfPartialFunctions.h"

MaximumOfPartialFunctions::MaximumOfPartialFunctions(PartialFunction** functions, int count) :functions(functions), count(count)
{
}

bool MaximumOfPartialFunctions::IsDefinedAtPoint(int32_t x) const
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

int32_t MaximumOfPartialFunctions::calculateTheResult(int32_t x) const
{
	if (!IsDefinedAtPoint(x))
	{
		throw std::out_of_range("Error.Not defined function!");
	}

	int32_t maxResult = functions[0]->calculateTheResult(x);

	for (int i = 1; i < count; ++i)
	{
		int32_t result = functions[i]->calculateTheResult(x);
		if (result > maxResult)
		{
			maxResult = result;
		}
	}
	return maxResult;
}

PartialFunction* MaximumOfPartialFunctions::clone() const
{
	return new MaximumOfPartialFunctions(*this);
}

int32_t MaximumOfPartialFunctions::operator()(int32_t x) const
{
	return calculateTheResult(x);
}

MaximumOfPartialFunctions::MaximumOfPartialFunctions() :functions(nullptr), count(0)
{
}

MaximumOfPartialFunctions::MaximumOfPartialFunctions(const MaximumOfPartialFunctions& other)
{
	copyFrom(other);
}

MaximumOfPartialFunctions::MaximumOfPartialFunctions(MaximumOfPartialFunctions&& other)noexcept
{
	moveFrom(std::move(other));
}

MaximumOfPartialFunctions& MaximumOfPartialFunctions::operator=(const MaximumOfPartialFunctions& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MaximumOfPartialFunctions& MaximumOfPartialFunctions::operator=(MaximumOfPartialFunctions&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MaximumOfPartialFunctions::~MaximumOfPartialFunctions()
{
	free();
}

void MaximumOfPartialFunctions::copyFrom(const MaximumOfPartialFunctions& other)
{
	count = other.count;
	functions = new PartialFunction * [count];

	for (int i = 0; i < count; ++i)
	{
		functions[i] = other.functions[i]->clone();
	}
}

void MaximumOfPartialFunctions::moveFrom(MaximumOfPartialFunctions&& other)noexcept
{
	count = other.count;
	functions = other.functions;

	other.count = 0;
	other.functions = nullptr;
}

void MaximumOfPartialFunctions::free()
{
	for (int i = 0; i < count; ++i)
	{
		delete functions[i];
	}

	delete[] functions;
	functions = nullptr;
	count = 0;
}