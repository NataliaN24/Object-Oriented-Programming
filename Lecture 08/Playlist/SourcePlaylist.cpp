#include<iostream>
#include<fstream>
#include"Playlist.h"


int main() {
    Playlist p;

    p.addSongToPlaylist("Song 2", Time(0, 1, 5), "rp", "song2.bin",p);
    p.addSongToPlaylist("Song 1", Time(0, 1, 55), "p", "song1.bin",p);

    std::cout << "Original Playlist:\n";
    p.printPlaylist();

    std::cout << "\nPlaylist sorted by name:\n";
    p.sortingByCriteria(p, sortByCriteria::sortByName);
    p.printPlaylist();

    std::cout << "\nPlaylist sorted by duration:\n";
    p.sortingByCriteria(p, sortByCriteria::sortByDuration);
    p.printPlaylist();

    std::cout << "\nSearching for 'Song 1':\n";
    p.searchSongByName("Song 1");

    std::cout << "\nSearching for 'Song 3 which is not in the playlist':\n";
    p.searchSongByName("Song 3");

    std::cout << "\nFinding songs with genre 'p':\n";
    p.searchAndPrintSongsBasedOnGenre((char)(Genre::pop));
    std::cout << "\nFinding songs with genre 'r':\n";
    p.searchAndPrintSongsBasedOnGenre((char) (Genre::rock));
    std::cout << "\nFinding songs with genre 'rp':\n";
    p.searchAndPrintSongsBasedOnGenre((char)(Genre::pop)| (char)(Genre::rock));

    std::cout << "\nMixing 'Song 1' with 'Song 2':\n";
    p.mixSongWithAnotherSong("Song 1", "Song 2");

    std::cout << "\nSaving 'Song 1' to 'song3.dat':\n";
    p.saveSongToFileByName("Song 1", "song3.bin", p);

    return 0;
}