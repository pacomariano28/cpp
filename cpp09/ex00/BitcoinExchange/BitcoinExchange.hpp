#pragma once

#include <map>
#include <string>
#include <fstream>
#include "../Exceptions.hpp"

#define BITCOIN_DB "Data/data.csv"

enum Type {
	DB, 
	INPUT
};

struct Date {
	int day;
	int month;
	int year;
	std::string dateStr;

	Date() : day(0), month(0), year(0), dateStr("") {}
};

struct Line {
    Date	date;
    float	value;
    
    Line() : date(), value(0.0f) {}
};

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string& inputFile);
		~BitcoinExchange();

	private:
		std::map<std::string, float> _rates;

		void	loadDatabase(void);
		void	processInput(const std::string& inputFile);
		Line 	parseLine(const std::string& line, Type type);
		Date 	getDate(const std::string& line);
		float	getValue(const std::string& line, Type type);
		void	findRate(const Line& parsedLine);
};