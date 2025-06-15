#include"polymorphic_ptr.hpp"
#include<utility>
#include<iostream>

template<typename T>
class HeterogeneousContainer 
{
	polymorphic_ptr<T>** data;
	size_t size;
	size_t capacity;

	void copyFrom(const HeterogeneousContainer<T>& other);
	void moveFrom(HeterogeneousContainer<T>&& other);
	void free();
	void resize();

public:
	HeterogeneousContainer();
	HeterogeneousContainer(const HeterogeneousContainer<T>& other);
	HeterogeneousContainer(HeterogeneousContainer<T>&& other)noexcept;
	HeterogeneousContainer<T>& operator=(const HeterogeneousContainer<T>& other);
	HeterogeneousContainer<T>& operator=( HeterogeneousContainer<T>&& other)noexcept;
	~HeterogeneousContainer();

	void add(const T* obj);
	void add(const T& obj);
	T& operator[](size_t index);
	const T& operator[](size_t index)const;
	T&  at(size_t index);
	const T&  at(size_t index)const;
	size_t getSize()const;


};

template<typename T>
inline void HeterogeneousContainer<T>::copyFrom(const HeterogeneousContainer<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new polymorphic_ptr<T>*[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = new polymorphic_ptr<T>(*other.data[i]);
	}
}

template<typename T>
inline void HeterogeneousContainer<T>::moveFrom(HeterogeneousContainer<T>&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.size = 0;
	other.capacity = 0;
	other.data = nullptr;
}

template<typename T>
inline void HeterogeneousContainer<T>::free()
{
	for (int i = 0; i < size; i++)
	{
		delete data[i];
	}
	delete[]data;
	size = capacity = 0;
}

template<typename T>
inline void HeterogeneousContainer<T>::resize()
{
	polymorphic_ptr<T>** result = new polymorphic_ptr<T>*[capacity * 2];
	for (int i = 0; i < size; i++)
	{
		result[i] = data[i]; //or std::move(data[i]
	}
	delete[] data;
	data = result;
	capacity *= 2;
}

template<typename T>
inline HeterogeneousContainer<T>::HeterogeneousContainer() : size(0), capacity(8) {
	data = new polymorphic_ptr<T>*[capacity];
}

template<typename T>
inline HeterogeneousContainer<T>::HeterogeneousContainer(const HeterogeneousContainer<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline HeterogeneousContainer<T>::HeterogeneousContainer(HeterogeneousContainer<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(const HeterogeneousContainer<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(HeterogeneousContainer<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline HeterogeneousContainer<T>::~HeterogeneousContainer()
{
	free();
}

template<typename T>
inline void HeterogeneousContainer<T>::add(const T* obj)
{
	if (size >= capacity)
	{
		resize();
	}
	data[size++] = new polymorphic_ptr<T>(obj->clone());
}

template<typename T>
inline void HeterogeneousContainer<T>::add(const T& obj)
{
	if (size >= capacity)
	{
		resize();
	}
	add(&obj);
}

template<typename T>
inline T& HeterogeneousContainer<T>::operator[](size_t index)
{
	if (index >= size)
	{
		throw  std::out_of_range("Error");
	}
	return **data[index];
}

template<typename T>
inline const T& HeterogeneousContainer<T>::operator[](size_t index) const
{
	if (index >= size)
	{
		throw  std::out_of_range("Error");
	}
	return **data[index];
}

template<typename T>
inline T& HeterogeneousContainer<T>::at(size_t index)
{
	if (index >= size)
	{
		throw  std::out_of_range("Error");
	}
	return **data[index];
}

template<typename T>
inline const T& HeterogeneousContainer<T>::at(size_t index) const
{
	if (index >= size)
	{
		throw  std::out_of_range("Error");
	}
	return **data[index];
}


template<typename T>
inline size_t HeterogeneousContainer<T>::getSize() const
{
	return size;
}
