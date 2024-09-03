//Задача 1. Реализирайте клас StringVector, който представлява динамична колекция от String обекти
//и има минимум следните функции :
//
//push_back - добавя елемент в края на вектора
//pop_back - премахва последния елемент на вектора
//insert - добавя елемент на даден индекс във вектора
//erase - изтрива елемент на даден индекс във вектора
//clear - изчиства данните във вектора
//operator[] - позволява индексация на елементите във вектора(работи в константно и неконстантно)
//empty - връща дали векторът е празен
//size - връща броя на елементите във вектора
//Bonus : добавете каквито прецените други фунцкии и оператори, които биха били смислени и полезни.
//(Пр : оператори за вход и изход от поток)
//
//За реализацията на класа използвайте предоставения клас String и неговите методи.При невалидни входни данни, 
//погрижете се класът да сигнализира с подходящи изключения.

#include<iostream>
#include"MyString.h"

class stringVector 
{
	MyString *data;
	unsigned capacity;
	unsigned size;

	void copyFrom(const stringVector& other)
	{
		size = other.size;
		capacity = other.capacity;
		data = new MyString[capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	void moveFrom(stringVector&& other) {
		data = other.data;
		capacity = other.capacity;
		size = other.size;
		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;
	}
	void free() {
		delete[]data;
	}
	void resize() {
		MyString* temp = new MyString[capacity * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[]data;
		data = temp;
		capacity *= 2;
	}

public:
	stringVector()
	{
		capacity = 4;
		size = 0;
		data = new MyString[capacity];
	}

	stringVector(const stringVector& other) 
	{
		copyFrom(other);
	}
	stringVector(stringVector&& other)
	{
		moveFrom(std::move(other));
	}
	stringVector& operator=(const stringVector& other) 
	{
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
	stringVector& operator=(stringVector&& other) 
	{
		if (this != &other) {
			free();
			moveFrom(std::move(other));
		}
		return *this;
	}
	~stringVector() 
	{
		free();

	}
	void push_back(const MyString& el)
	{
		if (size >= capacity) 
		{
			resize();
		}
		data[size++] = el;
	}
	void pop_back() 
	{
		if (size == 0)
         {
			throw std::out_of_range("Vector is empty");
		}
		--size;
	}
	void insert(unsigned index, const MyString& str) {
		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}
		if (size >= capacity) {
			resize();
		}
		for (size_t i = size; i > index; i--)
		{
			data[i]=std::move(data[i - 1]);
		}
		data[index] = str;
		++size;
	}
	void erase(unsigned index) {
		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}
		for (size_t i = index; i <size-1 ; i++)
		{
			data[i] = std::move(data[i + 1]);
		}
		--size;

	}
	void clear()
	{
		size = 0;
	}
	MyString& operator[](unsigned index) {
		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}
	const MyString& operator[](unsigned index)const 
	{
		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}
	bool empty()const
	{
		return size == 0;
	}
	size_t get_size()const
	{
		return size;
	}
	size_t get_capacity()const
	{
		return capacity;
	}
};
int main() {
	stringVector vec;

	vec.push_back(MyString("Hello"));
	vec.push_back(MyString("World"));
	vec.push_back(MyString("!"));

	for (size_t i = 0; i < vec.get_size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	vec.insert(1, MyString("Beautiful"));
	for (size_t i = 0; i < vec.get_size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	vec.pop_back();
	for (size_t i = 0; i < vec.get_size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	vec.erase(1);
	for (size_t i = 0; i < vec.get_size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	vec.clear();
	std::cout << "Vector cleared. Is empty: " << std::boolalpha << vec.empty() << std::endl;

	return 0;
}
