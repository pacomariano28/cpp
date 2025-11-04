#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>

#define BITCOIN_DB "Data/data.csv"

struct Date {
	int day;
	int month;
	int year;
	std::string err_msg;

	Date() : day(0), month(0), year(0), err_msg("") {}
};

struct ParsedLine {
    Date	date;
    float	value;
    std::string err_msg;
    
    ParsedLine() : value(0.0f), err_msg(""), date() {}
};

class BitcoinExchange {
	public:
		explicit BitcoinExchange(const std::string& inputFile);
		~BitcoinExchange();

	private:
		std::map<std::string, float> _rates;

		Date getDate(const std::string& line);
		
		// File processing methods
		void processInputFile(const std::string& filename);
		void processInputLine(std::string& line);
		void loadDatabase();
		void loadDatabaseLine(const std::string& line);
		
		// Validation methods
		bool isValidDateFormat(const std::string& date) const;
		bool isValidDateComponents(const std::string& date) const;
		bool isNumericString(const std::string& str, size_t expectedLength) const;
		bool isValidDateRange(const Date& date) const;
		bool isValidInputValue(float value) const;
		bool isFutureDate(const std::string& date) const;
		//bool isValidDatabaseValue(float value) const;
		
		// Utility methods
		std::string trimWhitespace(const std::string& str) const;
		size_t findFirstNonWhitespace(const std::string& str) const;
		size_t findLastNonWhitespace(const std::string& str) const;
		float parseFloat(const std::string& str, bool& success) const;
		ParsedLine parseLine(const std::string& line, char separator) const;
		
		// Helper methods
		//void validateFileOpen(const std::ifstream& fileStream, const char* errorMsg) const;
		void skipHeader(std::ifstream& fileStream) const;
		void displayResult(const std::string& date, float value, float rate) const;
		void displayError(std::string& err_msg, const std::string& context = "") const; // huh?
		
		// Rate finding
		float findRate(const std::string& date) const;
};

#endif