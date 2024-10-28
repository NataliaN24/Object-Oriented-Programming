#include "PremiumPlayer.h"

void PremiumPlayer::free()
{
    delete[]name;
}

void PremiumPlayer::copyFrom(const PremiumPlayer& other)
{
    name = new char[std::strlen(other.name) + 1];
    strcpy(this->name, other.name);
}

void PremiumPlayer::moveFrom(PremiumPlayer&& other)
{
    this->name = other.name;
    other.name = nullptr;
}

PremiumPlayer::PremiumPlayer(int id, unsigned int points, star stars, const char* name):Player(id,points,stars)
{
    setName(name);
}

PremiumPlayer::PremiumPlayer()
{
    name[0] = '\0';
}

const char* PremiumPlayer::getName() const
{
    return name;
}

void PremiumPlayer::setName(const char* newName)
{
    name = new char[std::strlen(newName) + 1];
    strcpy(this->name, newName);

}

bool PremiumPlayer::levelUp()
{
    if (getPoints() >= 256)
    {
        howManyStars(star::one);
        points -= 256;
        return true;
    }
}

PremiumPlayer::PremiumPlayer(const PremiumPlayer& other)
{
    copyFrom(other);
}

PremiumPlayer::PremiumPlayer(PremiumPlayer&& other) noexcept
{
    moveFrom(std::move(other));
}

PremiumPlayer& PremiumPlayer::operator=(const PremiumPlayer& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

PremiumPlayer& PremiumPlayer::operator=(PremiumPlayer&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

PremiumPlayer::~PremiumPlayer()
{
    free();
}
