#include"PartialFunction.h"
#include"MyPair.hpp"

template <typename T>
class PartialFunctionByCriteria :public PartialFunction
{
public:

	PartialFunctionByCriteria(const T& obj);
	PartialFunction* clone()const override;

	bool IsDefinedAtPoint(int32_t x)const override;

	int32_t calculateTheResult(int32_t x)const override;
	int32_t operator()(int32_t x)const;

	MyPair<bool, int32_t> getResult(int32_t x) const;

private:

	T function;
};

template<typename T>
PartialFunctionByCriteria<T>::PartialFunctionByCriteria(const T& obj) :function(obj)
{

}

template<typename T>
bool PartialFunctionByCriteria<T>::IsDefinedAtPoint(int32_t x) const
{
	MyPair<bool, int32_t> result = function(x);
	return result.getFirst();
}

template<typename T>
int32_t PartialFunctionByCriteria<T>::calculateTheResult(int32_t x) const
{
	MyPair<bool, int32_t> result = function(x);

	if (result.getFirst()) 
	{
		return result.getSecond();
	}
	else 
	{
		throw std::out_of_range("Error. Function not defined!");
	}
}

template<typename T>
 int32_t PartialFunctionByCriteria<T>::operator()(int32_t x) const
{
	 return calculateTheResult(x);
}

template<typename T>
PartialFunction* PartialFunctionByCriteria<T>::clone() const
{
	return new PartialFunctionByCriteria(*this);
}

template<typename T>
MyPair<bool, int32_t> PartialFunctionByCriteria<T>::getResult(int32_t x) const
{
	MyPair<bool, int32_t>result = function(x);
	return  MyPair<bool, int32_t>(result.getFirst(), result.getSecond());
}