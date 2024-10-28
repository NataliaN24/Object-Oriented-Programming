#pragma once
#include"Player.h"

class Guest:public Player
{
	unsigned int time=0;
	bool playing = true;

public:
	Guest(int id, unsigned int points, unsigned int time, bool playing);
	Guest()=default;
	unsigned int getTime()const;
	bool isPlayerPlaying()const;
	bool levelUp();
};
