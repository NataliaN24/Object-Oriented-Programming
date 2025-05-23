#pragma once
#include<iostream>
#include<fstream>

template<typename T, typename D>
class Pair {
protected:
	T first;
	D second;

public:
	Pair(const T& first, const D& second);
	Pair(T&& first, D&& second);
	Pair(const T& first, D&& second);
	Pair(T&& first, const D& second);

	T& getFirst();
	D& getSecond();
	const T& getFirst() const;
	const D& getSecond() const;

	void setFirst(const T& newValue);
	void setFirst(T&& newValue);
	void setSecond(const D& newValue);
	void setSecond(D&& newValue);

	template<typename T, typename D>
	friend std::istream& operator>>(std::istream& is, Pair<T, D>& p);
	template<typename T, typename D>
	friend std::ostream& operator<<(std::ostream& os, const Pair<T, D>& p);

	bool operator==(const Pair<T, D>& other)const;
	bool operator!=(const Pair<T, D>& other)const;
	bool operator<(const Pair<T, D>& other)const;
	bool operator<=(const Pair<T, D>& other)const;
	bool operator>=(const Pair<T, D>& other)const;
	bool operator>(const Pair<T, D>& other)const;

};


template<typename T, typename D>
Pair<T, D>::Pair(const T& first, const D& second) : first(first), second(second)
{}


template<typename T, typename D>
Pair<T, D>::Pair(T&& first, D&& second) : first(std::move(first)), second(std::move(second))
{}

template<typename T, typename D>
Pair<T, D>::Pair(const T& first, D&& second) : first(first), second(std::move(second))
{}

template<typename T, typename D>
Pair<T, D>::Pair(T&& first, const D& second) : first(std::move(first)), second(second)
{}

template<typename T, typename D>
T& Pair<T, D>::getFirst() {
	return first;
}

template<typename T, typename D>
D& Pair<T, D>::getSecond() {
	return second;
}

template<typename T, typename D>
const T& Pair<T, D>::getFirst() const {
	return first;
}

template<typename T, typename D>
const D& Pair<T, D>::getSecond() const {
	return second;
}

template<typename T, typename D>
void Pair<T, D>::setFirst(const T& newValue) {
	first = newValue;
}

template<typename T, typename D>
void Pair<T, D>::setFirst(T&& newValue) {
	first = std::move(newValue);
}

template<typename T, typename D>
void Pair<T, D>::setSecond(const D& newValue) {
	second = newValue;
}

template<typename T, typename D>
void Pair<T, D>::setSecond(D&& newValue) {
	second = std::move(newValue);
}

template<typename T, typename D>
inline bool Pair<T, D>::operator==(const Pair<T, D>& other) const
{
	return getFirst() == other.getFirst() && getSecond() == other.getSecond();
}

template<typename T, typename D>
inline bool Pair<T, D>::operator!=(const Pair<T, D>& other) const
{
	return !(*this == other);
}

template<typename T, typename D>
inline bool Pair<T, D>::operator<(const Pair<T, D>& other) const
{
	return getFirst() < other.getFirst() || (getFirst() == other.getFirst() && getSecond() < other.getSecond());
}

template<typename T, typename D>
inline bool Pair<T, D>::operator<=(const Pair<T, D>& other) const
{
	return  *this < other || *this == other;
}

template<typename T, typename D>
inline bool Pair<T, D>::operator>=(const Pair<T, D>& other) const
{
	return !(*this < other);
}

template<typename T, typename D>
inline bool Pair<T, D>::operator>(const Pair<T, D>& other) const
{
	return !(*this <= other);
}

template<typename T,typename D>
std::istream& operator>>(std::istream& is, Pair<T, D>& p)
{
	return is >> p.first >> p.second;
}

template<typename T, typename D>
std::ostream& operator<<(std::ostream& os, const Pair<T, D>& p)
{
	return os << "(" << p.getFirst() << "," << p.getSecond() << ")";
}
