#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

#define BITCOIN_DB	= "../Data/data.csv"

class BitcoinExchange {
	private:
		std::map<std::string, float> _rates;

		void	loadData(void);

	public:
		BitcoinExchange(std::string& file);
		~BitcoinExchange(void);
};

#endif