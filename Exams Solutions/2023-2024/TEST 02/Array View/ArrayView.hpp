#include<iostream>
#pragma once
#include <cstring>
#include <stdexcept>

template<typename T>
class ArrayView
{
	const T* begin = nullptr;
	const T* end = nullptr;

public:
	ArrayView(const T* arr) = delete;
	ArrayView(const T* arr, size_t size);

	const T& operator[](size_t index)const;

	size_t getSize()const;
	bool isEmpty()const;

	ArrayView<T>subArr(unsigned begIndex);
	ArrayView<T>subArr(unsigned begIndex, size_t size);

	template<class F>
	friend std::ostream& operator<<(std::ostream& os, const ArrayView<F>& view);
};

template<> //template specialization for strings!
ArrayView<char>::ArrayView(const char* arr) :ArrayView(arr,strlen(arr)){}

template <class T>
ArrayView<T>::ArrayView(const T* arr, size_t size) :begin(arr),end(begin+size){}


template <class T>
const T& ArrayView<T>::operator[](size_t ind) const
{
    return begin[ind];
}

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayView<T>& view) 
{
    const T* iter = view.begin;
    while (iter!= view.end)
    {
        os << (*iter);
        iter++;
    }
    return os;
}

template <class T>
size_t ArrayView<T>::getSize() const
{
    return end - begin;
}

template <class T>
bool ArrayView<T>::isEmpty() const
{
    return getSize() == 0;
}

template <class T>
ArrayView<T> ArrayView<T>::subArr(unsigned beginInd) 
{
    if (beginInd > getSize())
    {
        throw std::invalid_argument("Cannot create subview with larger starting index than the original view");
    }
    return ArrayView<T>(begin + beginInd, getSize() - beginInd);
    
}

template <class T>
ArrayView<T> ArrayView<T>::subArr(unsigned beginInd, size_t size) {
    if (size + beginIndex > getSize())
    {
        throw std::invalid_argument("Cannot create subview with larger scope than the original view");
    }
    return ArrayView<T>(begin + beginInd, size);
}
