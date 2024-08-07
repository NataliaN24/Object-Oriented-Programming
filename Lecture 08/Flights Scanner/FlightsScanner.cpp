#include "FlightsScanner.h"
#include "Utills.h"
#include <cstring>
#include <iostream>
#include <thread>         
#include <chrono>         
#include <fstream>
#include <sstream>
#include <cstdio>
#pragma warning (disable : 4996)

void FlightsScanner::handleAirport(char* airport) const
{
    if (strlen(airport) != 3)
    {
        throw std::length_error("The airport size should be exactly 3");
    }
    toUpper(airport);
}

void FlightsScanner::parseLine(const char* line, FlightRecord& rec) const
{
    std::stringstream current(line);
    current >> rec.origin;
    if (strlen(rec.origin) != 3)
    {
        throw std::length_error("The origin size should be exactly 3");
    }
    try {
        handleAirport(rec.origin);
    }
    catch (const std::exception & e)
        {
            std::cout << "Error while processing the origin. Given: " << rec.origin << std::endl;
            throw;
        }
    current >> rec.dest;
    if (strlen(rec.dest) != 3)
        throw std::length_error("The destination size should be exactly 3");

    try
    {
        handleAirport(rec.dest);
    }
    catch (const std::exception& exc)
    {
        std::cout << "Error while processing the destination. Given: " << rec.dest << std::endl;
        throw;
    }
    char amountStr[ORIGIN_AND_DEST_SIZE];
    try
    {
        rec.amount = convertToNumber(amountStr);
    }
    catch (const std::bad_cast& exc)
    {
        static const unsigned DEFAULT_AMOUNT = 50;
        std::cout << "Invalid amount. Setting to default value: " << DEFAULT_AMOUNT << std::endl;
        rec.amount = DEFAULT_AMOUNT;
        throw;
    }
    }


bool FlightsScanner::readAndExportData(std::ifstream& input)
{
	std::ofstream ofs(outputFileName, std::ios::out | std::ios::app);
	if (!ofs.is_open())
	{
		std::cout << "Could not open the output file" << std::endl;
		return false;
	}
	unsigned lineIndex = 0;

	bool errorOccured = false;
	while (!input.eof())
	{
		char line[1024];
		input.getline(line, 1024);

		FlightRecord record;
		try
		{
			parseLine(line, record);
			saveRecord(ofs, record);
		}
		catch (const std::invalid_argument& exc)
		{
			std::cout << "Invalid arugment occured on line " << lineIndex << ": " << exc.what() << ". The flight will NOT be saved! " << std::endl;
			errorOccured = true;
		}
		catch (const std::length_error& exc)
		{
			std::cout << "Lenght error occured on line " << lineIndex << ": " << exc.what() << ". The flight will NOT be saved! " << std::endl;
			errorOccured = true;
		}
		catch (const std::bad_cast& exc)
		{
			std::cout << "Bad cast error occured on line " << lineIndex << ": " << exc.what() << ". The flight will be saved! " << std::endl;
			saveRecord(ofs, record);
			errorOccured = true;
		}
		catch (const std::exception& exc)
		{
			std::cout << "Unknow error occured on line " << lineIndex << ": " << exc.what() << ". The flight will NOT be saved! " << std::endl;
			errorOccured = true;
		}
		catch (...)
		{
			std::cout << "Unknown error occured on line " << lineIndex << ". The flight will NOT be saved! " << std::endl;
			errorOccured = true;
		}
		lineIndex++;
	}
	return errorOccured;
}

void FlightsScanner::saveRecord(std::ofstream& ofs, const FlightRecord& rec) const
{
    const static double EURO_TO_LEV = 1.95;
    ofs << rec.origin << " " << rec.dest << " " << rec.amount * EURO_TO_LEV << std::endl;
}

FlightsScanner::FlightsScanner(const char* input, const char* output, int scanInterval)
{
	strcpy(inputFileName, input);
	strcpy(outputFileName, output);
	sec = scanInterval;
}

void FlightsScanner::run()
{
	while (true)
	{
		std::cout << "Scanning for file..." << std::endl;
		std::ifstream ifs(inputFileName);
		if (!ifs.fail()) {
			std::cout << "File found!" << std::endl;
			if (readAndExportData(ifs))
			{
				std::cout << "Successfully exported file!";
			}
			else
			{
				std::cout << "Error occured while exporting the file!";
			}

			ifs.close();
			remove(inputFileName);
		}
		else
		{
			std::cout << "File NOT found! Sleeping..." << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::seconds(sec)); 
	}
}
