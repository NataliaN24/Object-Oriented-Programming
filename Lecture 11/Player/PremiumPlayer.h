#pragma once
#include<cstring>
#include<iostream>
#include<exception>
#include "Player.h"
#pragma warning(disable:4996)

class PremiumPlayer:public Player
{
	char* name;

	void free();
	void copyFrom(const PremiumPlayer& other);
	void moveFrom(PremiumPlayer&& other);
public:
	PremiumPlayer();
	PremiumPlayer(const PremiumPlayer& other);
	PremiumPlayer(PremiumPlayer&& other)noexcept;
	PremiumPlayer& operator=(const PremiumPlayer& other);
	PremiumPlayer& operator=(PremiumPlayer&& other)noexcept;
	~PremiumPlayer();

	PremiumPlayer(int id, unsigned int points, star stars, const char* name);
	PremiumPlayer();
	const char* getName()const;
	void setName(const char* newName);
	bool levelUp()override;
};

