#pragma once

#include <map>
#include <string>
#include <fstream>
#include "../Exceptions/Exceptions.hpp"

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
	Type 	type;	
    std::string err_msg;
    
    Line() : date(), value(0.0f), type(DB), err_msg("") {}
};

class BitcoinExchange {
	public:
		explicit BitcoinExchange(const std::string& inputFile);
		~BitcoinExchange();

	private:
		std::map<std::string, float> _rates;

		void	loadDatabase(void);
		Date 	getDate(const std::string& line);
		
		
};