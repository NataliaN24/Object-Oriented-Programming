#include "Song.h"
#include<cstring>
#pragma warning(disable:4996)


Song::Song(const char* name, const Time& duration, unsigned char genreBits, const char* content) 
{
       setNameOfSong(name);
       setDuration(duration);
       setGenreBits(genreBits);
       setContent(content);
}

const char* Song::getNameOfSong() const 
{
    return name;
}
 
const Time& Song::getDuration() const
{
    return duration;
}

unsigned Song::getDurationInSeconds() const
{
    return duration.toSeconds();
}

unsigned char Song::getGenreBits() const 
{
    return genreBits;
}
    
const char* Song::getContent() const 
{
    return content;
}

void Song::setNameOfSong(const char* newName)
{
    if (strlen(newName) >= GLOBAL_CONSTANTS::MAX_NAME_LENGTH)
    {
        return;
    }
    else
    {
        strcpy(this->name, newName);
    }
}
  
void Song::setContent(const char* newContent) 
{
    if (strlen(newContent) >= GLOBAL_CONSTANTS::MAX_CONTENT_LENGTH) 
    {
        return;
    }
    else 
    {
        strcpy(this->content, newContent);
    }
}

void Song::setDuration(const Time& newDuration)
{
    duration = newDuration;
}

void Song::setGenreBits(unsigned char newGenreBits) 
{
    this->genreBits = newGenreBits;
}

bool Song::hasGenre(Genre genre) const
{
    return (genreBits & (char)(genre)) != 0;
}

void Song::addGenre(Genre genre) 
{
    genreBits |= (char)(genre);
}

void Song::printSong() const
{
    std::cout << "Name of song:" << getNameOfSong() << " . ";
    std::cout << "Duration: ";

    const Time& duration = getDuration();
    duration.printTime();
    
    std::cout<<"   Genres: ";
    if (hasGenre(Genre::rock)) std::cout << "rock ";
    if (hasGenre(Genre::pop)) std::cout << "pop ";
    if (hasGenre(Genre::hip_hop)) std::cout << "hip-hop ";
    if (hasGenre(Genre::electronic)) std::cout << "electronic ";
    if (hasGenre(Genre::jazz)) std::cout << "jazz ";
 
}

void Song::saveSongToFile(std::ofstream& ofs, const Song& song) const
{
    size_t lengthOfName = strlen(song.name);

    if (lengthOfName > GLOBAL_CONSTANTS::MAX_NAME_LENGTH)
    {
        return;
    }
    ofs.write((const char*)&lengthOfName, sizeof(lengthOfName));
    ofs.write((const char*)song.name, lengthOfName);
    ofs.write((const char*)&song.duration, sizeof(song.duration));
    ofs.write((const char*)&song.genreBits, sizeof(song.genreBits));

    size_t lengthOfContent = strlen(song.content);
    ofs.write((const char*)&lengthOfContent, sizeof(lengthOfContent));
    ofs.write((const char*)song.content, lengthOfContent);
}

bool Song::readSongFromFile(std::ifstream& ifs, Song& result)
{
    size_t lengthOfName;
    ifs.read((char*)&lengthOfName, sizeof(lengthOfName));

    char* nameBuffer = new char[lengthOfName + 1];
    ifs.read(nameBuffer, lengthOfName);
    nameBuffer[lengthOfName] = '\0';
    result.setNameOfSong(nameBuffer);
    delete[] nameBuffer;

    ifs.read((char*)&result.duration, sizeof(result.duration));
    ifs.read((char*)&result.genreBits, sizeof(result.genreBits));

    size_t lengthOfContent;
    ifs.read((char*)&lengthOfContent, sizeof(lengthOfContent));
    char* contentBuffer = nullptr;
    contentBuffer = new char[lengthOfContent + 1];

    ifs.read(contentBuffer, lengthOfContent);
    contentBuffer[lengthOfContent] = '\0';
    result.setContent(contentBuffer);
    delete[] contentBuffer;

    return true;
}

void Song::mixWithTrack(const char* track)
{
    int contentLength = strlen(content);
    int trackLength = strlen(track);

    for (int i = 0; i < contentLength && i < trackLength; ++i)
    {
        content[i] ^= track[i];
    }
}

void Song::addExtraBit(int k)
{
    if (k <= 0)
    {
        std::cerr << "Error: Invalid index k." << std::endl;
        return;
    }

    int contentLength = strlen(content);

    for (int i = 0; i < contentLength; ++i)
    {
        char originalChar = content[i];

        int bitIndex = 0;

        while (bitIndex < CONSTANTS_BITS::BITS)
        {

            if ((bitIndex + 1) % k == 0)
            {

                originalChar |= (1 << bitIndex);
            }
            bitIndex++;
        }
        content[i] = originalChar;
    }
}

Song:: ~Song() {}