#pragma once
#include<iostream>
#include<utility>//for std::move

//This implementation is taken ready from github of G.Terziev

template<typename T, typename D>
class MyPair 
{
	T first;
	D second;

public:
	MyPair(const T& first, const D& second);
	MyPair(T&& first, D&& second);
	MyPair(const T& first, D&& second);
	MyPair(T&& first, const D& second);

	T& getFirst();
	D& getSecond();
	const T& getFirst() const;
	const D& getSecond() const;

	void setFirst(const T& newValue);
	void setFirst(T&& newValue);
	void setSecond(const D& newValue);
	void setSecond(D&& newValue);
};

template<typename T, typename D>
MyPair<T, D>::MyPair(const T& first, const D& second) : first(first), second(second)
{}


template<typename T, typename D>
MyPair<T, D>::MyPair(T&& first, D&& second) : first(std::move(first)), second(std::move(second))
{}

template<typename T, typename D>
MyPair<T, D>::MyPair(const T& first, D&& second) : first(first), second(std::move(second))
{}

template<typename T, typename D>
MyPair<T, D>::MyPair(T&& first, const D& second) : first(std::move(first)), second(second)
{}

template<typename T, typename D>
T& MyPair<T, D>::getFirst() {
	return first;
}

template<typename T, typename D>
D& MyPair<T, D>::getSecond() {
	return second;
}

template<typename T, typename D>
const T& MyPair<T, D>::getFirst() const {
	return first;
}

template<typename T, typename D>
const D& MyPair<T, D>::getSecond() const {
	return second;
}

template<typename T, typename D>
void MyPair<T, D>::setFirst(const T& newValue) {
	first = newValue;
}

template<typename T, typename D>
void MyPair<T, D>::setFirst(T&& newValue) {
	first = std::move(newValue);
}

template<typename T, typename D>
void MyPair<T, D>::setSecond(const D& newValue) {
	second = newValue;
}

template<typename T, typename D>
void MyPair<T, D>::setSecond(D&& newValue) {
	second = std::move(newValue);
}