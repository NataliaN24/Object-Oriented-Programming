#pragma once
class NumberSeries
{
	
	int* generatedValues;
	int(*func)(int);
	int startValue;
	int capacity;
	int size;
	
	void resize();
	void resetSeries();
	void copyFrom(const NumberSeries& other);
	void moveFrom(NumberSeries&& other);
	void free();

	public:

	NumberSeries();
	NumberSeries(const NumberSeries& other);
	NumberSeries(NumberSeries&& other)noexcept;
	NumberSeries& operator=(const NumberSeries& other);
	NumberSeries& operator=(NumberSeries&& other)noexcept;
	~NumberSeries();

	NumberSeries(int initialValue, int(*function)(int));
	bool contains(int number);
	int getElement(int i);
	void setStartValue(int newValue);
	void setFunction(int(*func)(int));

};