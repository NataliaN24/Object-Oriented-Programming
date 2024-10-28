#include "Player.h"

Player::Player(int id, unsigned int points, star stars):id(id),points(points),stars(stars)
{
}

int Player::getId() const
{
    return id;
}

unsigned int Player::getPoints() const
{
    return points;
}

star Player::getStars() const
{
    return stars;
}

bool Player::levelUp() 
{
    if (points >= 256 &&points<512 )
    {
        howManyStars(star::two);
        points -= 256;
        return true;

    }
    else if (points >= 512&&points<1024 && stars == star::two)
    {
        howManyStars(star::three);
        points -= 512;
        return true;
    }
    else if (points >= 1024&&points<2048 && stars == star::three)
    {
        howManyStars(star::four);
        points -= 1024;
        return true;
    }
    else if (points >= 2048 && stars == star::four)
    {
        howManyStars(star::five);
        points -= 2048;
        return true;
    }
    else {
        return false;
    }
}

void Player::howManyStars(star _stars)
{
    if (_stars == star::one)
    {
        starsCollected += 1;
    }
    else if (_stars == star::two)
    {
        starsCollected += 2;
    }
    else if (_stars == star::three)
    {
        starsCollected += 3;
    }
    else if (_stars == star::four)
    {
        starsCollected += 4;
    }
    else if (_stars == star::five)
    {
        starsCollected += 5;
    }
    
    
}
