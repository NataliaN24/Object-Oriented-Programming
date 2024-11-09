#pragma once
#include<iostream>
#include"time.h"
#include"date.h"
#include"AccessRights.h"
const int NAME_LENGTH = 64;
const int CONTENT_LENGTH= 512;

class File {
	char _name[NAME_LENGTH + 1];
	char _content[CONTENT_LENGTH + 1];
	int size;
	Time _creationTime;
	Time _modificationTime;
	Date _creationDate;
	Date _modificationDate;
	AccessRights _UserAccessRights;
public:
	File();
	File(const char* filename, const char* content, int size, const Time& creationTime, const Time& modificationTime, const Date& creationDate, 
		const Date& modificationDate,const AccessRights&userAccessRights );
	
	void setName(const char* filename);
	void setContent(const char *cont);
	void  setSize(int filesize);
	void setCreationTime(const Time& creationTime);
	void setModificationTime(const Time& modificationTime);
	void setCreationDate(const Date& creationDate);
	void setModificationDate(const Date& modificationDate);
	void setUserAccessRights(const AccessRights& userAccessRights);
	void printAccessRights(char userType) const;

	const char* getName()const;
	const char *getContent()const;
	int getSize()const;
	const  Time& getCreationTime()const;
	const Time& getModificationTime()const;
	const Date& getCreationDate()const;
	const Date& getModificationDate()const;
	const AccessRights& getAccessRights()const;

};
