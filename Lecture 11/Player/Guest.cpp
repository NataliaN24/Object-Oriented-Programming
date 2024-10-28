#include "Guest.h"


Guest::Guest(int id, unsigned int points, unsigned int time, bool playing):Player(id,points,star::one)
{
    this->time = time;
    this->playing = playing;
}

unsigned int Guest::getTime() const
{
    return time;
}

bool Guest::isPlayerPlaying() const
{
    return true;
}

bool Guest::levelUp()
{
    return false;
}
