#pragma once
enum class star
{
	one,
	two,
	three,
	four,
	five,
	unknown
};
class Player
{
protected:
	int id=0;
	unsigned int points=0;
	star stars=star::one;
	int starsCollected=1;

public:
	Player()=default;
	Player(int id, unsigned int points, star stars);
	int getId()const;
	unsigned int getPoints()const;
	star getStars()const;
	virtual bool levelUp();
	 void  howManyStars(star _stars);

};