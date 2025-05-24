#include<iostream>
#include<cstring>
#include<fstream>
#pragma warning(disable:4996)

template<typename T>
class Named
{
	char* name;
	T data;

	void copyFrom(const Named<T>& other)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->data = other.data;
	}
	void moveFrom(Named<T>&& other) {
		this->name = other.name;
		this->data = other.data;
		other.name = nullptr;
	}
	void free()
	{
		delete[]name;
	}

public:
	Named():name(new char[1]{'\0'}), data() {}
	Named(const Named<T>& other) { copyFrom(other); }
	Named(const char* name, const T& data)
	{
		setName(name);
		setData(data);
	}
	Named(Named<T>&& other) { moveFrom(std::move(other)); }
	Named& operator=(const Named<T>& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}
	Named& operator=(Named<T>&& other)
	{
		if (this != &other)
		{
			free();
			moveFrom(std::move(other));
		}
		return *this;

	}
	~Named() { free(); }


	const char* getName()const { return name; }
	const T& getData()const { return data; }
	void setName(const char* newName) {
		delete[]this->name;
		if (newName)
		{
			this->name = new char[strlen(newName) + 1];
			strcpy(this->name, newName);
		}
	}
	void setData(const T& newData) {
		this->data = newData;
	}

	template <typename X>
	friend std::ostream& operator<<(std::ostream& os, const Named<X>& other) {
		return os << other.name << " " << other.data;
	}
	template<typename X>
	friend std::istream& operator>>(std::istream& is, Named<X>& other)
	{
		char buffer[1024];
		is >> buffer >> other.data;
		other.setName(buffer);
		return is;
	}
};
