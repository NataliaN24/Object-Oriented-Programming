#include <iostream>
#include "GamePlatform.h"


int main()
{
    Game game1("The Witcher 3", 50, true);
    Game game2("Minecraft", 30, true);
    Game game3("Valorant", 0, true);

    GamePlatform platform;
    platform.addGame(game1);
    platform.addGame(game2);
    platform.addGame(game3);

    std::cout << "All Games:\n";
    platform.print();

    std::cout << "\nGames Sorted by Price:\n";
    platform.printByPrice();

    std::cout << "\nFree Games:\n";
    platform.printByFree();

    std::ofstream ofs("games.txt");
    platform.saveToFile(ofs);
    ofs.close();

    // Read from file doesn't work properly
    std::ifstream ifs("games.txt");
    GamePlatform loadedPlatform;
    loadedPlatform.readFromFile(ifs);
    ifs.close();

    std::cout << "\nLoaded Platform:\n";
    loadedPlatform.print();

    return 0;
}
