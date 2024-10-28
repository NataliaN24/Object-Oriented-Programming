#pragma once
#include<cstring>
#include<iostream>
#include<exception>
#include "Player.h"
#pragma warning(disable:4996)

constexpr int MaxSize = 8;

class LoggedPlayer:public Player
{
	char password[MaxSize + 1] = " ";
	bool isLogged=false;
public:
	LoggedPlayer(int id, unsigned int points, star stars, const char* pass);
	LoggedPlayer();
	const char* getPassword()const;
	void setPassword(const char* newPass);
	bool isLoggedIn()const;
	bool logIn(const char*pass,int id);

};

