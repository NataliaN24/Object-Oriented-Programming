#include "BaseCase.h"

BaseCase::BaseCase(int32_t* inputs, uint16_t N) : inputs(inputs), N(N)
{
}

BaseCase::~BaseCase()
{
	free();
}

BaseCase::BaseCase() :inputs(nullptr), N(0)
{
}

BaseCase::BaseCase(const BaseCase& other)
{
	copyFrom(other);
}

BaseCase::BaseCase(BaseCase&& other)noexcept
{
	moveFrom(std::move(other));
}

BaseCase& BaseCase::operator=(const BaseCase& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

BaseCase& BaseCase::operator=(BaseCase&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void BaseCase::copyFrom(const BaseCase& other)
{
	if (other.inputs != nullptr)
	{
		inputs = new int32_t[other.N];
		for (uint16_t i = 0; i < other.N; ++i)
		{
			inputs[i] = other.inputs[i];
		}
	}
	else
	{
		inputs = nullptr;
	}

	N = other.N;
}

void BaseCase::moveFrom(BaseCase&& other)noexcept
{
	inputs = other.inputs;
	N = other.N;

	other.inputs = nullptr;
	other.N = 0;
}

void BaseCase::free()
{
	delete[] inputs;
	inputs = nullptr;
	N = 0;
}