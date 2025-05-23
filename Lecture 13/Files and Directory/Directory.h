#pragma once
#include"File.h"

class Directory:public File
{
	File** files;
	size_t count;
	size_t capacity;

	void copyFrom(const Directory& other);
	void resize();
	void free();

public:

	Directory();
	Directory(const char* name);
	Directory(const Directory& other);
	Directory& operator=(const Directory& other);
	~Directory();
	void printContent()const override;
	virtual File* clone()const override;

	void addFile(const File* newFile);

};

