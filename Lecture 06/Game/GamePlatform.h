#pragma once
#include"Game.h"
#include<fstream>
#pragma warning(disable:4996)

constexpr int MAX_CAPACITY = 100;
constexpr int MAX_TITLE = 256;
class GamePlatform
{
	Game* games;
	int count;
	int capacity;

	void copyFrom(const GamePlatform& other);
	void free();
public:
	GamePlatform();
	GamePlatform(const Game* games, int count, int cap);
	GamePlatform(const GamePlatform& other);
	GamePlatform& operator=(const GamePlatform& other);
	~GamePlatform();

	void addGame(const Game& other);
	void printByIndex(int index)const;
	void print()const;
	void printByPrice()const;
	void printByFree()const;
	void remove(const Game& other);
	void saveToFile(std::ofstream& ofs);
	void readFromFile(std::ifstream& ifs);

};

