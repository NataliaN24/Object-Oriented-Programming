#pragma once
#include"EventBase.h"
#include"my_string.h"


template<>
class Event<my_string> :public EventBase
{
	my_string  payload;

public:
	Event(const my_string& obj);
	virtual void print()const override;
	virtual void serialize()const override;
	virtual EventBase* clone()const override;
};

Event<my_string>::Event(const my_string& obj) :payload(obj)
{
}

void Event<my_string>::print() const
{
	std::cout << "Payload:" << payload;
}

void Event<my_string>::serialize() const
{
	std::cout << "<Payload>";
}

inline EventBase* Event<my_string>::clone() const
{
	return new Event(*this);
}



template<typename T>
class Event:public EventBase
{
	T payload;

public:
	Event(const T& obj);
	virtual void print()const override;
	virtual void serialize()const override;
	virtual EventBase* clone()const override;
};

template<typename T>
 Event<T>::Event(const T& obj):payload(obj)
{
}


 template<typename T>
 void Event<T>::print() const
{
	 std::cout << "Payload:"<<payload;
}

 template<typename T>
 void Event<T>::serialize() const
 {
	 std::cout << "<Payload>";
 }

 template<typename T>
 inline EventBase* Event<T>::clone() const
 {
	 return new Event(*this);
 }

