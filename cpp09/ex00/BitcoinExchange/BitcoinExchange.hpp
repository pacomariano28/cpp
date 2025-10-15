#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>

#define BITCOIN_DB "Data/data.csv"

struct ParsedLine {
    std::string date;
    float value;
    bool isValid;
    
    ParsedLine() : value(0.0f), isValid(false) {}
};

class BitcoinExchange {
	public:
		explicit BitcoinExchange(const std::string& inputFile);
		~BitcoinExchange();

	private:
		std::map<std::string, float> _rates;
		
		// File processing methods
		void processInputFile(const std::string& filename);
		void processInputLine(const std::string& line);
		void loadDatabase();
		void loadDatabaseLine(const std::string& line);
		
		// Validation methods
		bool isValidDateFormat(const std::string& date) const;
		bool isValidDateComponents(const std::string& date) const;
		bool isNumericString(const std::string& str, size_t expectedLength) const;
		bool isValidDateRange(const std::string& monthStr, const std::string& dayStr) const;
		bool isValidInputValue(float value) const;
		bool isValidDatabaseValue(float value) const;
		
		// Utility methods
		std::string trimWhitespace(const std::string& str) const;
		size_t findFirstNonWhitespace(const std::string& str) const;
		size_t findLastNonWhitespace(const std::string& str) const;
		float parseFloat(const std::string& str, bool& success) const;
		ParsedLine parseLine(const std::string& line, char separator) const;
		
		// Helper methods
		void validateFileOpen(const std::ifstream& fileStream, const char* errorMsg) const;
		void skipHeader(std::ifstream& fileStream) const;
		void displayResult(const std::string& date, float value, float rate) const;
		void displayError(const char* errorMsg, const std::string& context = "") const;
		
		// Rate finding
		float findRate(const std::string& date) const;
};

#endif