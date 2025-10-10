#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

#define BITCOIN_DB "Data/data.csv"

enum FileType {
    INPUT_FILE = ',',
    DDBB_FILE = '|'
};

class BitcoinExchange {
	private:
		std::map<std::string, float> _rates;
		std::map<std::string, float> _input;

		void	loadData(const char* file, FileType type, std::map<std::string, float>& container);

	public:
		BitcoinExchange(std::string& inputFile);
		~BitcoinExchange(void);
};

#endif