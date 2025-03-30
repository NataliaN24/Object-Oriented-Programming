#pragma once
#include<iostream>
#pragma warning(disable:4996)
class Game
{
	char* title;
	size_t price;
	bool isAvailable;
	void copyFrom(const Game& other);
	void free();

public:
	Game();
	Game(const Game& other);
	Game(const char* title, size_t price, bool isAvailable);
	Game& operator=(const Game& other);
	~Game();

	void setTitle(const char* newTitle);
	void setPrice(size_t price);
	void setAvailability(bool available);

	const char* getTitle()const;
	size_t getPrice()const;
	bool getAvailability()const;

	void print()const;
};

