#include "Directory.h"

void Directory::copyFrom(const Directory& other)
{
    count = other.count;
    capacity = other.capacity;
    files = new File * [capacity];
    for (size_t i = 0; i < count; ++i) {
        files[i] = other.files[i]->clone();
    }

}

void Directory::resize()
{
    capacity *= 2;
    File** newFiles = new File * [capacity];
    for (size_t i = 0; i < count; ++i)
        newFiles[i] = files[i];
    delete[] files;
    files = newFiles;
}

void Directory::free()
{
    for (size_t i = 0; i < count; ++i)
        delete files[i];
    delete[] files;
}


Directory::Directory():File(""), count(0), capacity(4) {
    files = new File * [capacity];
}

Directory::Directory(const char* name):File(name), count(0), capacity(4)
{
        files = new File * [capacity];
}

Directory::Directory(const Directory& other)
{
    copyFrom(other);
}

Directory& Directory::operator=(const Directory& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Directory::~Directory()
{
    free();
}

void Directory::printContent() const
{
    for (int i = 0; i < count; i++)
    {
        files[i]->printContent();
    }
}

File* Directory::clone() const
{
    return new Directory(*this);
}

void Directory::addFile(const File* newFile)
{
    if (count == capacity)
    {
        resize();
    }
    files[count++] = newFile->clone();
}
