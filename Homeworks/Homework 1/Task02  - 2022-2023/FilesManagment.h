#pragma once
#include<iostream>
#include"FileSystem.h"
const int MAX_FILES = 100;

class FileManager {
	File* files;
	int maxFiles;
	int currentNum_files;

public:
	FileManager(int maxFiles);
	~FileManager();
	void createFile(const char*filename,const Time& CreationTime);
	void editFile(const char*filename,const char*content,const Time&modificationTime, const Date& modificationDate);
	void addTextToFile(const char* filename, const char* content, int size, int modificiationHour, int modificationMinutes, int modificationSeconds,
	int modificationDay, int modificationMonth, int modificationYear, AccessRights userRights);
	void deleteFile(const char*filename);
	void changeRights(const char* filename, char userType, char userRole);
	void printInfoForAFile(const char*filename);
	void printContents(const char* filename, char userType);
	void printAllFiles()const;
	void SortFilesByName();
	void SortFilesByCreationTime();
	void SortFilesByModificationTime();
	void SortFilesBySize();
	void writeToFile(const char* filename);
	void readToFile(const char* filename);



};