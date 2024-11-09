#include<iostream>
#include"FileSystem.h"
#include"AccessRights.h"
#pragma warning(disable : 4996)

void my_strcpy(char* dest, const char* src, size_t destSize) {
	size_t i = 0;
	while (i < destSize - 1 && src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

File::File() {
	_name[0] = '\0';
	_content[0] = '\0';
	size = 0;
	_creationTime=Time(0, 0, 0);
	_modificationTime = Time(0, 0, 0);
	_creationDate = Date(0,0,0);
	_modificationDate = Date(0, 0, 0);
	_UserAccessRights=AccessRights();

}

File::File(const char* filename, const char* content, int size, const Time& creationTime, const Time& modificationTime, const Date& creationDate,
	const Date& modificationDate, const AccessRights& userAccessRights) :_creationTime(creationTime), _modificationTime(modificationTime), _creationDate(creationDate), _modificationDate(modificationDate),
	_UserAccessRights(userAccessRights)
{
	setName(filename);
	setContent(content);
	setSize(size);
	setCreationTime(creationTime);
	setModificationTime(modificationTime);
	setCreationDate(creationDate);
	setModificationDate(modificationDate);
	setUserAccessRights(userAccessRights);
}

const char* File::getName()const {
	return _name;

}
const char* File::getContent()const {
	return _content;

}
 int File::getSize()const {
	return size;
}
const Time& File::getCreationTime()const {
	return _creationTime;

}
const Time& File::getModificationTime()const {
	return _modificationTime;
}
const Date& File::getCreationDate()const {
	return _creationDate;
}
const Date& File::getModificationDate()const {
	return _modificationDate;
}
const AccessRights& File::getAccessRights()const {
	return _UserAccessRights;
}
void File::setName(const char* filename) {
	if (strlen(filename) > 64) {
		return;
	}
	else {
		my_strcpy(_name, filename,NAME_LENGTH+1);
	}
}
void File::setContent(const char* cont) {
	if (strlen(cont) > 512) {
		return;
	}
	else {
		my_strcpy(_content, cont,CONTENT_LENGTH+1);
	}
}
void File::setSize(int filesize) {
	size = filesize;

}
void File::setCreationTime(const Time& creationTime) {
	this->_creationTime = creationTime;

}
void File::setModificationTime(const Time& modificationTime) {
	this->_modificationTime = modificationTime;

}
void  File::setCreationDate(const Date& creationDate) {
	this -> _creationDate = creationDate;

}
void File::setModificationDate(const Date& modificationDate) {
	this->_modificationDate = modificationDate;

}
void File::setUserAccessRights(const AccessRights& userAccessRights) {
	this->_UserAccessRights = userAccessRights;

}

void File::printAccessRights(char userType) const {
	const AccessRights& rights = getAccessRights();
	std::cout << "Access rights: ";
	std::cout << (rights.hasReadPermission( 'u') ? "r" : "-")
		<< (rights.hasWritePermission( 'u') ? "w" : "-")
		<< (rights.hasExecutePermission( 'u') ? "x" : "-") << " ";
	std::cout << (rights.hasReadPermission( 'g') ? "r" : "-")
		<< (rights.hasWritePermission( 'g') ? "w" : "-")
		<< (rights.hasExecutePermission( 'g') ? "x" : "-") << " ";
	std::cout << (rights.hasReadPermission( 'o') ? "r" : "-")
		<< (rights.hasWritePermission( 'o') ? "w" : "-")
		<< (rights.hasExecutePermission( 'o') ? "x" : "-") << " ";
	std::cout << std::endl;

}
