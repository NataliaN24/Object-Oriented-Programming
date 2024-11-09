#pragma once
#include"HelperUtils.h"
#include"Song.h"

class Playlist 
{
    Song songs[GLOBAL_CONSTANTS::MAX_SONGS];
    size_t numberOfSongs;

public:

    Playlist();

    void setNumberOfSongs(size_t numberSongs);
    size_t getNumberOfSong()const;

    void readAndAddSongFromFile(const char* filename, const char* name, const Time& duration, unsigned char genreBits, Playlist& playlist);
    void addSongToPlaylist(const char* name, const Time& duration, const char* genre, const char* filename,Playlist& playlist);
   
    void printPlaylist()const;

    void saveSongsToFile(const char* filename, const Playlist& playlist)const;
    void saveSongToFileByName(const char* songName, const char* fileName, const Playlist& playlist)const;
    void readPlaylistFromFile(std::ifstream& ifs,  Playlist& playlist);

    bool searchSongByName( const char* name)const;
    void searchAndPrintSongsBasedOnGenre( unsigned char bitsOfgenre)const;
   
    void sortPlaylistOfSongs(Playlist& playlist, bool(*isLess)(const Song& lhs, const Song& rhs));
    void sortingByCriteria(Playlist& pl, sortByCriteria criteria);

    void mixSongWithAnotherSong(const char* song1Name, const char* song2Name);
    void addExtraBitToSongOfPlaylist(const char* songName, int k);

    ~Playlist();
};