#pragma once
#include"File.h"

class TextFile:public File
{
	char* content;

	void copyFrom(const TextFile& other);
	void free();
public:
	TextFile();
	TextFile(const TextFile& other);
	TextFile& operator=(const TextFile& other);
	~TextFile();
	TextFile(const char* name, const char* content);
	void setContent(const char* newContent);
	const char* getContent()const;
	void printContent()const override;
	virtual File* clone()const;


};

