#pragma once
#include"Event.hpp"

template<typename T>
class MetricEvent:public Event<T>
{
public:
	MetricEvent(const T& payload);
	virtual void print()const override;
	virtual void serialize()const override;
	virtual EventBase* clone()const override;
};

template<typename T>
inline MetricEvent<T>::MetricEvent(const T& payload):Event<T>(payload)
{
}

template<typename T>
inline void MetricEvent<T>::print() const
{
	std::cout << "Metric:";
}

template<typename T>
inline void MetricEvent<T>::serialize() const
{
	std::cout << "<MetricEvent>";
}

template<typename T>
inline EventBase* MetricEvent<T>::clone() const
{
	return new MetricEvent(*this);
}
