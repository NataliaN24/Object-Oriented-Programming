#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

namespace CONSTANTS
{
    constexpr int LENGTH = 128;
    constexpr int MAX_USERS = 100;
}

struct User
{
    char name[CONSTANTS::LENGTH + 1];
    char email[CONSTANTS::LENGTH + 1];
    char password[CONSTANTS::LENGTH + 1];
};

void saveUser(const char* filename, const User& user)
{
    std::ofstream ofs(filename, std::ios::app);
    if (!ofs.is_open())
    {
        throw std::runtime_error("Error opening file for appending.");
    }
    ofs << user.name << std::endl;
    ofs << user.email << std::endl;
    ofs << user.password << std::endl;
}

void readUser(std::ifstream& ifs, User& user)
{
    if (!ifs.is_open())
    {
        throw std::runtime_error("Error opening file for reading.");
    }
    ifs.getline(user.name, CONSTANTS::LENGTH);
    ifs.getline(user.email, CONSTANTS::LENGTH);
    ifs.getline(user.password, CONSTANTS::LENGTH);
}

struct System
{
    User users[CONSTANTS::MAX_USERS];
    size_t count;
};

bool isValidCount(size_t count)
{
    return count <= CONSTANTS::MAX_USERS;
}

void saveSystemToFile(const char* filename, const System& st)
{
    std::ofstream ofs(filename, std::ios::trunc);
    if (!ofs.is_open())
    {
        throw std::runtime_error("Error opening file for writing.");
    }
    ofs << st.count << std::endl;
    for (size_t i = 0; i < st.count; ++i)
    {
        saveUser(filename, st.users[i]);
    }
}

void readSystemFromFile(const char* filename, System& st)
{
    std::ifstream ifs(filename);
    if (!ifs.is_open())
    {
        throw std::runtime_error("Error opening file for reading.");
    }
    ifs >> st.count;
    ifs.ignore(); 
    if (!isValidCount(st.count))
    {
        throw std::out_of_range("The number of users exceeds the maximum limit.");
    }
    for (size_t i = 0; i < st.count; ++i)
    {
        readUser(ifs, st.users[i]);
    }
}

bool checkForRegisteredUser(const System& st, const User& u)
{
    for (size_t i = 0; i < st.count; ++i)
    {
        if (strcmp(st.users[i].email, u.email) == 0 &&
            strcmp(st.users[i].password, u.password) == 0)
        {
            return true;
        }
    }
    return false;
}

void registerUser(System& st, const char* filename)
{
    if (st.count >= CONSTANTS::MAX_USERS)
    {
        throw std::out_of_range("Cannot register more users, limit reached.");
    }

    User newUser;
    std::cout << "Enter name:" << std::endl;
    std::cin.getline(newUser.name, CONSTANTS::LENGTH);

    std::cout << "Enter email:" << std::endl;
    std::cin.getline(newUser.email, CONSTANTS::LENGTH);

    std::cout << "Enter password:" << std::endl;
    std::cin.getline(newUser.password, CONSTANTS::LENGTH);

    st.users[st.count++] = newUser;
    saveSystemToFile(filename, st);
}

bool login(const char* filename, const System& st, User& user)
{
    std::cin.ignore();  

    std::cout << "Enter email to login:" << std::endl;
    std::cin.getline(user.email, CONSTANTS::LENGTH);

    std::cout << "Enter password:" << std::endl;
    std::cin.getline(user.password, CONSTANTS::LENGTH);

    if (checkForRegisteredUser(st, user))
    {
        std::cout << "Login Successful!" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    System system;
    system.count = 0;

   
    User users[5] = {
        {"Alice Smith", "alice.smith@example.com", "passwordAlice"},
        {"Bob Johnson", "bob.johnson@example.com", "passwordBob"},
        {"Charlie Brown", "charlie.brown@example.com", "passwordCharlie"},
        {"David Wilson", "david.wilson@example.com", "passwordDavid"},
        {"Eve Davis", "eve.davis@example.com", "passwordEve"}
    };

    for (int i = 0; i < 5; ++i) {
        system.users[i] = users[i];
    }
    system.count = 5;
    saveSystemToFile("system.txt", system);
    

    std::cout << "Users saved successfully. System file updated." << std::endl;

    try
    {
       readSystemFromFile("system.txt", system);

        User user;
        if (login("system.txt", system, user))
        {
            std::cout << "Welcome !" << std::endl;
        }
        else
        {
            std::cout << "Failed to log in!" << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown error occurred." << std::endl;
    }

    return 0;
}
