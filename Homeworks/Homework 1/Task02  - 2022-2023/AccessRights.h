#pragma once
#include<iostream>
const int MAX = 9;
class AccessRights {
private:
	bool readPermission[3];
	bool writePermission[3];
	bool executePermission[3];
	char userType;
public:
	AccessRights();
	void setPermission(const char* accessRights);
	bool hasReadPermission( char userType)const;
	bool hasWritePermission( char userType)const;
	bool hasExecutePermission( char userType)const;
	void setReadPermission(int userRole, bool value);
	void setWritePermission(int userRole, bool value);
	void setExecutePermission(int userRole, bool value);
	void printPermissions() const;
};
