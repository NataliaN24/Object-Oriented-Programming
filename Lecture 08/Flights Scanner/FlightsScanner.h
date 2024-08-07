#pragma once
#include<fstream>
#include"Utills.h"
constexpr int MAX_SIZE = 1024;
constexpr int ORIGIN_AND_DEST_SIZE = 64;
class FlightsScanner
{
	char inputFileName[MAX_SIZE] = " ";
	char outputFileName[MAX_SIZE] = " ";
	int sec = -1;
	unsigned lineIndex = 0;

	struct FlightRecord
	{
		char origin[ORIGIN_AND_DEST_SIZE];
		char dest[ORIGIN_AND_DEST_SIZE];
		unsigned amount;
	};
	void handleAirport(char* airport)const;
	void parseLine(const char* line, FlightRecord& rec)const;
	bool readAndExportData(std::ifstream& ifs);
	void saveRecord(std::ofstream& ofs, const FlightRecord& rec)const;

public:
	FlightsScanner(const char* input, const char* output, int scanInterval);
	void run();
};

