#pragma once
#include"Event.hpp"

template<typename T>
class LogEvent:public Event<T>
{
public:
	LogEvent(const T& payload);
	virtual void print()const override;
	virtual void serialize()const override;
	virtual EventBase* clone()const override;
};

template<typename T>
inline LogEvent<T>::LogEvent(const T& payload):Event<T>(payload)
{
}

template<typename T>
inline void LogEvent<T>::print() const
{
	std::cout << "Log:";
}

template<typename T>
void LogEvent<T>::serialize() const
{
	std::cout << "<LogEvent>";
}

template<typename T>
inline EventBase* LogEvent<T>::clone() const
{
	return new LogEvent(*this);
}
