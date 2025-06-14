#pragma once
#include"Event.hpp"

template<typename T>
class AlarmEvent:public Event
{
public:
	AlarmEvent(const T& payload);
	virtual void print()const override;
	virtual void serialize()const override;
	virtual EventBase* clone()const override;
};

template<typename T>
inline AlarmEvent<T>::AlarmEvent(const T& payload):Event<T>(payload)
{
}

template<typename T>
inline void AlarmEvent<T>::print() const
{
	std::cout << "Alarm:";
}

template<typename T>
inline void AlarmEvent<T>::serialize() const
{
	std::cout << "<AlarmEvent>";
}

template<typename T>
inline EventBase* AlarmEvent<T>::clone() const
{
	return new AlarmEvent(*this);
}
