#pragma once
#include"Peak.h"

class Collection
{
	Peak** peaks;
	size_t size;
	size_t capacity;

	void copyFrom(const Collection& other);
	void free();
	void resize();

public:
	Collection();
	Collection(const Collection& other);
	Collection& operator=(const Collection& other);
	~Collection();

	void addPeak(const Peak* obj);
	void addPeak(const Peak& obj);
	void removePeak(const Peak& obj);
	Peak* getPeakAt(size_t index);
	void printPeaks()const;
};

