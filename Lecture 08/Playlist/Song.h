#pragma once
#include"HelperUtils.h"
#include"Time.h"
#include<iostream>
#include<fstream>

class Song 
{
    Time duration;
    unsigned char genreBits = 0;
    char name[GLOBAL_CONSTANTS::MAX_NAME_LENGTH+1] = "";
    char content[GLOBAL_CONSTANTS::MAX_CONTENT_LENGTH+1] = "";

public:

    Song() = default;

    Song(const char* name, const Time& duration, unsigned char genreBits, const char* content);

    const char* getNameOfSong() const;
    const Time& getDuration() const; 
    unsigned getDurationInSeconds() const;
    unsigned char getGenreBits() const;
    const char* getContent() const;

    void setNameOfSong(const char* newName);
    void setContent(const char* newContent);
    void setDuration(const Time& newDuration);
    void setGenreBits(unsigned char newGenreBits);

    bool hasGenre(Genre genre) const;
    void addGenre(Genre genre);

    void printSong() const;

    void addExtraBit(int k);
    void mixWithTrack(const char* track);

    void saveSongToFile(std::ofstream& ofs, const Song& song)const;
    bool readSongFromFile(std::ifstream& ifs, Song& result);

    ~Song();
};