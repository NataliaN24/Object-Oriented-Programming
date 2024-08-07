#pragma once
class StringPool
{
public:

	StringPool();
	const char* getAllocatedString(const char* str);
	void releaseString(const char* str);
	StringPool(const StringPool&) = delete;
	StringPool& operator=(const StringPool&) = delete;
	~StringPool();

private:

	struct StringRecord
	{
		char* str;
		unsigned refCount = 0;
	};
	StringRecord* strRecords;
	size_t stringCount = 0;
	size_t stringCapacity = 0;

	void removeRecord(unsigned index);
	void resize(unsigned newCap);
	int findAllocatedString(const char* str)const;
	unsigned allocatedString(const char* str);
};