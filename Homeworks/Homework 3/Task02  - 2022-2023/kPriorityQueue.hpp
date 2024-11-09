#include<iostream>
#include<exception>
#include"MyQueue.hpp"

template<typename T>
class kPriorityQueue
{

	MyQueue<T>* queues;
	size_t maxQueuePriority;
	size_t count;

	void copyFrom(const kPriorityQueue<T>& other);
	void moveFrom(kPriorityQueue<T>&& other);
	void free();


public:
	kPriorityQueue()=default;
	kPriorityQueue(const kPriorityQueue<T>& other);
	kPriorityQueue(kPriorityQueue<T>&& other);
	kPriorityQueue(const size_t maxPriority);
	kPriorityQueue<T>& operator= (const kPriorityQueue<T>& other);
	kPriorityQueue<T>& operator= (kPriorityQueue<T>&& other);

	void push(const T& obj,size_t priority);
	void push(T&& obj, size_t priority);

	void pop();

	const T& peek() const;
	bool isEmpty() const;

	~kPriorityQueue();

};

template<typename T>
void kPriorityQueue<T>::copyFrom(const kPriorityQueue<T>& other)
{
	maxQueuePriority = other.maxQueuePriority;
	queues = new MyQueue<T>[other.maxQueuePriority];

	for (size_t i = 0; i < maxQueuePriority; i++) 
	{
		queues[i] = other.queues[i];
	}

	count = other.count;
}

template<typename T>
void kPriorityQueue<T>::moveFrom(kPriorityQueue<T>&& other)
{
	maxQueuePriority = other.maxQueuePriority;
	count = other.count;
	queues = other.queues;

	other.maxQueuePriority = 0;
	other.count = 0;
	other.queues = nullptr;

}

template<typename T>
void  kPriorityQueue<T>::free() 
{
	delete[]queues;
	maxQueuePriority = 0;
	count = 0;
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue( const size_t maxPriority)
{
	if (maxPriority == 0) 
	{
		throw std::out_of_range("Error ! No priorities!");
	}
	maxQueuePriority = maxPriority;
	queues = new MyQueue<T>[maxQueuePriority];
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(const kPriorityQueue<T>& other) 
{
	copyFrom(other);
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(kPriorityQueue<T>&& other) 
{
	moveFrom(std::move(other));
}

template<typename T>
kPriorityQueue<T>& kPriorityQueue<T>:: operator= (const kPriorityQueue<T>& other)
{
	if (this != &other) 
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
kPriorityQueue<T>& kPriorityQueue<T>::operator= (kPriorityQueue<T>&& other) 
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
kPriorityQueue<T>::~kPriorityQueue()
{
	free();
}

template<typename T>
void  kPriorityQueue<T>::push(const T& obj, size_t priority)
{
	if (priority >= maxQueuePriority)
	{
		throw::std::out_of_range("This priority doesn't exist!");
	}
	
	queues[priority].push(obj);
	count++;
}

template<typename T>
void kPriorityQueue<T>::push(T&& obj, size_t priority)
{
	if (priority >= maxQueuePriority)
	{
		throw::std::out_of_range("This priority doesn't exist!");
	}
	
	queues[priority].push(std::move(obj));
	count++;
}

template<typename T>
void  kPriorityQueue<T>::pop()
{
	if (isEmpty())
	{
		throw std::logic_error("Empty queue!");
	}

	for (size_t i = maxQueuePriority - 1; i >= 0; i--)
	{
		if (!queues[i].isEmpty())
		{
			queues[i].pop();
			count--;
			return;
		}
	}
}

template<typename T>
const T& kPriorityQueue<T>::peek() const 
{
	if (isEmpty())
	{
		throw std::logic_error("Empty queue!");
	}

	for (size_t i = maxQueuePriority - 1; i >= 0; i--) 
	{
		if (!queues[i].isEmpty()) 
		{
			return queues[i].peek();
		}
	}
	throw std::logic_error("Empty queue!");
}

template<typename T>
bool kPriorityQueue<T>::isEmpty() const
{
	return count == 0;
}