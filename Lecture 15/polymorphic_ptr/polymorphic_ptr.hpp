#pragma once

template<typename T>
class polymorphic_ptr
{
	T* data;

	void copyFrom(const polymorphic_ptr& other);
	void moveFrom(polymorphic_ptr&& other);
	void free();
public:
	polymorphic_ptr();
	polymorphic_ptr(T* data);
	polymorphic_ptr(const polymorphic_ptr& other);
	polymorphic_ptr&operator=(const polymorphic_ptr& other);
	polymorphic_ptr(polymorphic_ptr&& other);
	polymorphic_ptr&operator=(polymorphic_ptr&& other);

	 ~polymorphic_ptr();

	T* operator->();
	const T* operator->() const;
	T& operator*();
	const T& operator*() const;
	operator bool() const;
	void reset(T* data);
	T* get();
	const T* get() const;

};

template<typename T>
inline void polymorphic_ptr<T>::copyFrom(const polymorphic_ptr& other)
{
	this->data = other.data->clone();
}

template<typename T>
inline void polymorphic_ptr<T>::moveFrom(polymorphic_ptr&& other)
{
	this->data = other.data;
	other.data = nullptr;

}

template<typename T>
inline void polymorphic_ptr<T>::free()
{
	delete data;
}

template<typename T>
inline polymorphic_ptr<T>::polymorphic_ptr()
{
	data = nullptr;
}

template<typename T>
inline polymorphic_ptr<T>::polymorphic_ptr(T* data)
{
	this->data = data;
}

template<typename T>
inline polymorphic_ptr<T>::polymorphic_ptr(const polymorphic_ptr& other)
{
	copyFrom(other);
}

template<typename T>
 polymorphic_ptr<T>& polymorphic_ptr<T>::operator=(const polymorphic_ptr<T>& other)
{
	 if (this != &other)
	 {
		 free();
		 copyFrom(other);
	}
	 return *this;
}

template<typename T>
inline polymorphic_ptr<T>::polymorphic_ptr(polymorphic_ptr&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
inline polymorphic_ptr<T>& polymorphic_ptr<T>::operator=(polymorphic_ptr&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline polymorphic_ptr<T>::~polymorphic_ptr()
{
	free();
}

template<typename T>
inline T* polymorphic_ptr<T>::operator->()
{
	return data;
}

template<typename T>
inline const T* polymorphic_ptr<T>::operator->() const
{
	return data;
}

template<typename T>
inline T& polymorphic_ptr<T>::operator*()
{
	return *data;
}

template<typename T>
inline const T& polymorphic_ptr<T>::operator*() const
{
	return *data;
}

template<typename T>
inline polymorphic_ptr<T>::operator bool() const
{
	return data != nullptr;
}

template<typename T>
inline void polymorphic_ptr<T>::reset(T* newData)
{
	if (data != newData) {
		delete data;
		data = newData;
	}
}

template<typename T>
inline T* polymorphic_ptr<T>::get()
{
	return data;
}

template<typename T>
inline const T* polymorphic_ptr<T>::get() const
{
	return data;
}
