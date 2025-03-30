#include "Game.h"

void Game::copyFrom(const Game& other)
{
    title = new char[strlen(other.title) + 1]; 
    strcpy(title, other.title);  
    price = other.price;
    isAvailable = other.isAvailable;
}

void Game::free()
{
    delete[] title;
}

Game::Game()
{
    title = nullptr;
    price = 0;
    isAvailable = false;
}

Game::Game(const Game& other)
{
    copyFrom(other);
}

Game::Game(const char* title, size_t price, bool isAvailable)
{
    setTitle(title);
    setPrice(price);
    setAvailability(isAvailable);
}

Game& Game::operator=(const Game& other)
{
    if (this != &other) {  
        free();  
        copyFrom(other);  
    }
    return *this;
}

Game::~Game()
{
    free();
}

void Game::setTitle(const char* newTitle)
{
    delete[] title; 
    title = new char[strlen(newTitle) + 1];  
    strcpy(title, newTitle);
}

void Game::setPrice(size_t price)
{
    this->price = price;
}

void Game::setAvailability(bool available)
{
    isAvailable = available;
}

const char* Game::getTitle() const
{
    return title;
}

size_t Game::getPrice() const
{
    return price;
}

bool Game::getAvailability() const
{
    return isAvailable;
}

void Game::print() const
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << std::endl;
}
