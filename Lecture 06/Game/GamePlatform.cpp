#include "GamePlatform.h"

void GamePlatform::copyFrom(const GamePlatform& other)
{
    games = new Game[other.capacity];
    count = other.count;
    capacity = other.capacity;
    for (int i = 0; i < count; i++) {
        games[i] = other.games[i];
    }
}

void GamePlatform::free()
{
    delete[]games;
}

GamePlatform::GamePlatform()
{
    capacity = MAX_CAPACITY;
    games = new Game[capacity];
    count = 0;
}

GamePlatform::GamePlatform(const Game* games, int count, int cap)
{
    capacity = cap;
    this->count = count;
    games = new Game[capacity];
    for (int i = 0; i < count; i++)
    {
        this->games[i] = games[i];
    }
}

GamePlatform::GamePlatform(const GamePlatform& other)
{
    copyFrom(other);
}

GamePlatform& GamePlatform::operator=(const GamePlatform& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

GamePlatform::~GamePlatform()
{
    free();
}

void GamePlatform::addGame(const Game& other)
{
    if (count < capacity) {
        games[count++] = other;
    }
}

void GamePlatform::printByIndex(int index)const
{
    if (index >= 0 && index < count) {
        games[index].print();
    }
}

void GamePlatform::print() const
{
    for (int i = 0; i < count; i++)
    {
        games[i].print();
        std::cout << std::endl;
    }
}

void GamePlatform::printByPrice() const
{
    int minPrice = UINT_MAX;
    int indexOfMostExpensive = 0;
    int indexOfChepeast = 0;
    int maxPrice = 0;

    for (int i = 0; i < count; i++)
    {
        if (games[i].getPrice() < minPrice)
        {
            minPrice = games[i].getPrice();
            indexOfChepeast = i;
        }
        if (games[i].getPrice() > maxPrice)
        {
            maxPrice = games[i].getPrice();
            indexOfMostExpensive = i;
        }

    }
    printByIndex(indexOfChepeast);
    printByIndex(indexOfMostExpensive);
    
}

void GamePlatform::printByFree() const
{
    for (int i = 0; i < count; i++)
    {
        if (games[i].getPrice() == 0)
        {
            games[i].print();
        }
    }
}

void GamePlatform::remove(const Game& other)
{
    int index = -1;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(games[i].getTitle(), other.getTitle()) == 0)
        {
            index = i;
            break;
        }
    }

    if (index != -1) {
        std::swap(games[index], games[count - 1]);
        count--;
    }
}

void GamePlatform::saveToFile(std::ofstream& ofs)
{
    if (!ofs.is_open())
    {
        return;
    }
    ofs << capacity << " " << count;
    for (int i = 0; i < count; i++)
    {
       
        ofs << games[i].getTitle() << " " << games[i].getAvailability() << " " << games[i].getPrice() << std::endl;
    }

}

void GamePlatform::readFromFile(std::ifstream& ifs)
{
    if (!ifs.is_open())
    {
        return;
    }
    ifs >> capacity >> count;
    free();
    games = new Game[capacity];
    char buffer[MAX_TITLE];
    bool isAvailable;
    size_t price;
    for (int i = 0; i < count; i++)
    {
        ifs >> std::ws;
        ifs.getline(buffer, sizeof(buffer));
        games[i].setTitle(buffer);
        ifs >>  isAvailable >> price;
        games[i].setAvailability(isAvailable);
        games[i].setPrice(price); 
        ifs.ignore();
    }
}
