#pragma once
#include"EventBase.h"

template<const size_t capacity>
class Container
{
	EventBase** events;
	size_t size;

	void copyFrom(const Container& other);
	void free();
	void resize(size_t newCap);
public:
	Container();
	Container(const Container<capacity>& other);
	Container& operator=(const Container<capacity>& other);
	~Container();

	void add(const EventBase& other);
	void pop();
	void print_all()const;


};

template<size_t capacity>
inline void Container<capacity>::copyFrom(const Container& other)
{
	events = new EventBase * [capacity];
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		this->events[i] = other.events[i]->clone();
	}
}

template<size_t capacity>
inline void Container<capacity>::free()
{
	for (int i = 0; i < size; i++)
	{
		delete events[i];
	}
	delete[]events;
}

template<size_t capacity>
inline void Container<capacity>::resize(size_t newCap)
{
	EventBase** result = new EventBase * [newCap];
	for (int i = 0; i < size; i++)
	{
		result[i] = events[i];
	}
	delete[]events;
	events = result;
	capacity = newCap;



}

template<size_t capacity>
inline Container<capacity>::Container()
{
	capacity = 8;
	size = 0;
	events = new EventBase * [capacity];
}

template<size_t capacity>
inline Container<capacity>::Container(const Container<capacity>& other)
{
	copyFrom(other);
}

template<size_t capacity>
inline Container& Container<capacity>::operator=(const Container<capacity>& other)
{
	// TODO: insert return statement here
}



template<size_t capacity>
inline Container<capacity>::~Container()
{
	free();
}

template<size_t capacity>
inline void Container<capacity>::add(const EventBase& other)
{
	if(size>=capacity)
	{
		resize(capacity * 2);
	}
	events[size++] = other.clone();
}

template<size_t capacity>
inline void Container<capacity>::pop()
{
	delete events[size - 1];
	size--;
}

template<size_t capacity>
inline void Container<capacity>::print_all() const
{
	for (int i = 0; i < size; i++)
	{
		events[i]->print();
		events[i]->serialize();
	}
}
