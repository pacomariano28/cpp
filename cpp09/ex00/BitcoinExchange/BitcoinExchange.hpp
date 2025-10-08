#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, float> _rates;

		void	loadData(std::string& file);

	public:
		BitcoinExchange(std::string& file);
		~BitcoinExchange(void);
};

#endif