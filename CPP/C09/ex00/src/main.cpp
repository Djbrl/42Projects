#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange	btcDatabaseParser("data.csv");
	std::ifstream	inputFile(av[1]);
	std::string		line;

	if (ac != 2 && inputFile.fail())
	{
		std::cout << "Error: Invalid numbers of arguments or file" << std::endl;
		return 1;
	}
	while (std::getline(inputFile, line))
	{
		if (line.find(" | ") != 10 || line.size() < 14)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = line.substr(0, 10);
		std::string value = line.substr(13, line.length());
		if (!BitcoinExchange::checkDbDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		const std::string errorType = BitcoinExchange::checkFileValue(value);
		if (errorType != "VALID")
		{
			std::cout << errorType << std::endl;
			continue ;
		}
		std::cout << date << " => " << value << " = " << btcDatabaseParser.getValue(date, value) << std::endl;
	}
	inputFile.close();
	return 0;
}
