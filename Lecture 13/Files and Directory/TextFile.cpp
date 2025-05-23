#include "TextFile.h"

void TextFile::copyFrom(const TextFile& other)
{
    content = new char[strlen(other.content) + 1];
    strcpy(content, other.content);
}

void TextFile::free()
{
    delete[] content;
    content = nullptr;
}

TextFile::TextFile():File(""), content(nullptr)
{
}

TextFile::TextFile(const TextFile& other)
{
    copyFrom(other);
}

TextFile& TextFile::operator=(const TextFile& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

TextFile::~TextFile()
{
    free();
}

TextFile::TextFile(const char* name, const char* content):File(name)
{
    setContent(content);
}

void TextFile::setContent(const char* newContent)
{
    delete[]content;
    content = new char[strlen(newContent) + 1];
    strcpy(this->content, newContent);
}

const char* TextFile::getContent() const
{
    return content;
}

void TextFile::printContent() const
{
    std::cout << getName() << " " << content;
}

File* TextFile::clone() const
{
    return new TextFile(*this);
}
