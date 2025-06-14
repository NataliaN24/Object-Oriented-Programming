#include <iostream>
template<typename T>
class Intersection
{
	const T* a;
	const T* b;
public:
	Intersection(const T& set1, const T& set2);
	int operator()(int num)const;
	void setA(const T& a);
	void setB(const T& b);
};

template<typename T>
inline Intersection<T>::Intersection(const T& set1, const T& set2):a(&set1),b(&set2)
{
}

template<typename T>
inline int Intersection<T>::operator()(int num) const
{
	return std::min((*a)(num), (*b)(num));
}

template<typename T>
inline void Intersection<T>::setA(const T& a)
{
	this->a = a;
}

template<typename T>
inline void Intersection<T>::setB(const T& b)
{
	this->b = b;
}
