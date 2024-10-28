#include "LoggedPlayer.h"

LoggedPlayer::LoggedPlayer(int id, unsigned int points, star stars, const char *pass):Player(id, points, stars)
{
    setPassword(pass);
}

LoggedPlayer::LoggedPlayer()
{
    password[0] = '\0';
}

const char* LoggedPlayer::getPassword() const
{
    return nullptr;
}

void LoggedPlayer::setPassword(const char* newPass)
{
    if (std::strlen(newPass) > MaxSize)
    {
        throw ("out of limit");
    }
    strcpy(this->password, newPass);

}

bool LoggedPlayer::isLoggedIn() const
{
    return isLogged;
}

bool LoggedPlayer::logIn(const char* pass, int id)
{
    if (strcmp(this->password, pass) == 0 && this->getId() == id)
    {
        std::cout << "Logging in was successful";
        isLogged = true;
        return true;
     }
    else {
        std::cout << "Logging in was not successful";
        isLogged = false;
        return false;
    }
}
