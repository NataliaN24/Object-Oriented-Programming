#include<cstring>
#include<iostream>
#include "Playlist.h"
#pragma warning (disable:4996)

Playlist::Playlist() 
{
    numberOfSongs = 0;
}

void Playlist::setNumberOfSongs(size_t numberSongs) 
{
    if (numberSongs > 1 && numberSongs < GLOBAL_CONSTANTS::MAX_SONGS) 
    {
        numberOfSongs = numberSongs;
    }
}

size_t  Playlist::getNumberOfSong()const
{
    return numberOfSongs;
}

void Playlist::readAndAddSongFromFile(const char* filename, const char* name, const Time& duration, unsigned char genreBits, Playlist& playlist)
{
    std::ifstream file(filename, std::ios::in|std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "File could not be opened" << std::endl;
        return;
    }

    size_t sizeOfFile = getFileSize(file);
    size_t contentArrayCount = sizeOfFile / sizeof(int);
    if (contentArrayCount > GLOBAL_CONSTANTS::MAX_CONTENT_LENGTH)
    {
        std::cerr << "Content is too long" << std::endl;
        return;
    }

    char* contentOfFile = new char[sizeOfFile + 1];

    file.read((char*)contentOfFile, sizeOfFile);
    contentOfFile[sizeOfFile] = '\0';

    playlist.songs[playlist.numberOfSongs++] = Song(name, duration, genreBits, contentOfFile);
    playlist.setNumberOfSongs(playlist.numberOfSongs);
    file.close();
    delete[] contentOfFile;
}

void Playlist::addSongToPlaylist(const char* name, const Time& duration, const char* genre, const char* filename, Playlist& playlist) 
{
    if (playlist.numberOfSongs >= GLOBAL_CONSTANTS::MAX_SONGS) 
    {
        std::cerr << "Maximum number of songs reached. Song could not be added to the playlist." << std::endl;
        return;
    }
    if (strlen(name) >= GLOBAL_CONSTANTS::MAX_CONTENT_LENGTH)
    {
        std::cerr << "Name of song is too long" << std::endl;
        return;
    }

    unsigned char genreBits = 0;

    for (const char* ptr = genre; *ptr != '\0'; ++ptr) 
    {
        switch (*ptr)
        {
        case 'r':
            genreBits |= (unsigned char)Genre::rock;
            break;
        case 'p':
            genreBits |= (unsigned char)Genre::pop;
            break;
        case 'h':
            genreBits |= (unsigned char)Genre::hip_hop;
            break;
        case 'e':
            genreBits |= (unsigned char)Genre::electronic;
            break;
        case 'j':
            genreBits |= (unsigned char)Genre::jazz;
            break;
        default:
            std::cerr << "Error: Invalid genre character '" << *ptr << "'." << std::endl;
            return;
        }
    }

    readAndAddSongFromFile(filename, name, duration, genreBits, playlist);
}

void  Playlist::printPlaylist()const 
{
    std::cout << "Playlist:\n";

    for (size_t i = 0; i < numberOfSongs; ++i)
    {
        songs[i].printSong();
        std::cout << std::endl;
    }
}

void  Playlist::saveSongsToFile(const char* filename, const Playlist& playlist)const
{
    std::ofstream file(filename, std::ios::out | std::ios::binary);

    if (!file.is_open()) 
    {
        std::cerr << "File could not be opened" << std::endl;
        return;
    }

    file.write((const char*)&playlist.numberOfSongs, sizeof(playlist.numberOfSongs));

    for (size_t i = 0; i < playlist.numberOfSongs; i++)
    {
        playlist.songs[i].saveSongToFile(file,playlist.songs[i]);
    }

    file.close();
}

void Playlist::readPlaylistFromFile(std::ifstream& ifs, Playlist& playlist) 
{
    size_t numberOfSongs;
    ifs.read((char*)&numberOfSongs, sizeof(numberOfSongs));
    playlist.setNumberOfSongs(numberOfSongs);

    for (size_t i = 0; i < playlist.getNumberOfSong(); i++)
    {
        Song s;
        s.readSongFromFile(ifs, s);
        playlist.songs[i] = s;

    }
}

bool Playlist::searchSongByName(const char* name) const
{
    for (size_t i = 0; i < numberOfSongs; ++i) 
    {
        if (strcmp(songs[i].getNameOfSong(), name) == 0)
        {
            std::cout << "Song is in the playlist" << std::endl;
            songs[i].printSong();
            return true;
        }
    }
    std::cout << "Song is not in the playlist" << std::endl;
    return false;
}

void Playlist::searchAndPrintSongsBasedOnGenre( unsigned char bitsOFgenre)const
{
   
    bool found = false;
    for (size_t i = 0; i < getNumberOfSong(); ++i)
    {
        if (songs[i].getGenreBits() == bitsOFgenre)
        {
            found = true;
            songs[i].printSong();
        }  
    }

    if (!found)
    {
        std::cout << "The song with the wanted genre is not found in the playlist" << std::endl;
    }
  
}

void Playlist::saveSongToFileByName(const char* songName, const char* fileName, const Playlist& playlist)const
{
    for (size_t i = 0; i < playlist.getNumberOfSong(); ++i)
    {
        if (strcmp(playlist.songs[i].getNameOfSong(), songName) == 0) 
        {
            std::ofstream ofs(fileName, std::ios::binary);
            if (!ofs.is_open()) 
            {
                std::cerr << "File could not be opened" << std::endl;
                return; 
            }
            playlist.songs[i].saveSongToFile(ofs, playlist.songs[i]); 
            ofs.close();
            return; 
        }
    }
    std::cerr << "Song not found in the playlist." << std::endl;
}

void Playlist::mixSongWithAnotherSong(const char* song1Name, const char* song2Name)
{
    size_t song1Index = -1;
    size_t song2Index = -1;
    for (size_t i = 0; i < numberOfSongs; ++i)
    {
        if (strcmp(songs[i].getNameOfSong(), song1Name) == 0) 
        {
            song1Index = i;
        }
        if (strcmp(songs[i].getNameOfSong(), song2Name) == 0)
        {
            song2Index = i;
        }
    }

    if (song1Index != -1 && song2Index != -1) 
    {
     
        songs[song1Index].mixWithTrack(songs[song2Index].getContent());

        std::cout << "Songs mixed successfully." << std::endl;
    }
    else
    {
        std::cerr << "One or both songs not found in the playlist." << std::endl;
        
    }
}

void Playlist::sortPlaylistOfSongs(Playlist& playlist, bool(*isLess)(const Song& lhs, const Song& rhs))
{
    for (int i = 0; i < playlist.getNumberOfSong(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < playlist.getNumberOfSong(); j++)
        {
            if (isLess(playlist.songs[j], playlist.songs[minIndex]))
                minIndex = j;

        }
        if (i != minIndex)
            std::swap(playlist.songs[i], playlist.songs[minIndex]);
    }
}

void Playlist::sortingByCriteria(Playlist& pl, sortByCriteria criteria)
{
    switch (criteria)
    {
    case sortByCriteria::sortByName: return sortPlaylistOfSongs(pl, [](const Song& lhs, const Song& rhs) { return strcmp(lhs.getNameOfSong(), rhs.getNameOfSong()) < 0; });
    case sortByCriteria::sortByDuration: return sortPlaylistOfSongs(pl, [](const Song& lhs, const Song& rhs) { return lhs.getDurationInSeconds() < rhs.getDurationInSeconds(); });

    }
}

void Playlist::addExtraBitToSongOfPlaylist(const char* songName, int k)
{
    for (size_t i = 0; i < numberOfSongs; ++i) 
    {
        if (strcmp(songs[i].getNameOfSong(), songName) == 0) {
            songs[i].addExtraBit(k);
            break; 
        }
    }
}

Playlist:: ~Playlist() {}