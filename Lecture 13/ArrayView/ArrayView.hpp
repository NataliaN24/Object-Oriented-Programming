#include<iostream>
#include<fstream>
#include<cstring>

template<typename T>
class ArrayView
{
protected:
	const T* begin;
	const T* end;

public:
	ArrayView(const T* arr) = delete;
	ArrayView(const T* array, size_t size);
	const T& operator[](size_t index)const;

	template<typename S>
	friend std::ostream &operator<<(std::ostream& os, const ArrayView<S>& arr);
	size_t getNumberOfElements()const;
	bool isEmpty()const;

	ArrayView<T> subArr(unsigned begIndex)const;
	ArrayView<T> subArr(unsigned begIndex, size_t size)const;


};

template<typename T>
  ArrayView<T>::ArrayView(const T* array, size_t size):begin(array),end(array +size)
{
}

template<>
ArrayView<char>::ArrayView(const char*arr): ArrayView(arr,strlen(arr)){}

template<typename T>
 const T& ArrayView<T>::operator[](size_t index) const
{
	return begin[index];
}


template<typename T>
 size_t ArrayView<T>::getNumberOfElements() const
{
	return end-begin;
}

template<typename T>
 bool ArrayView<T>::isEmpty() const
{
	return getNumberOfElements() == 0;
}

template<typename T>
 ArrayView<T> ArrayView<T>::subArr(unsigned begIndex) const
{
	if (begIndex > getNumberOfElements())
	{
		throw std::invalid_argument("Cannot create subview with larger starting index than the original view");
	}
	return ArrayView<T>(begin + begIndex, getNumberOfElements() - begIndex);
}

template<typename T>
 ArrayView<T> ArrayView<T>::subArr(unsigned begIndex, size_t _size) const
{
	if (begIndex + _size>getNumberOfElements())
	{
		throw std::invalid_argument("Cannot create subview with larger scope than the original view");
	}
	return ArrayView<T>(begin + begIndex, _size);
	
}

template<typename S>
 std::ostream& operator<<(std::ostream& os, const ArrayView<S>& arr)
{
	const S* iterator = arr.begin;
	while (iterator != arr.end)
	{
		os << *iterator;
		iterator++;
	}
	return os;

}
