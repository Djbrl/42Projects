#include "BitcoinExchange.hpp"

//UTILS
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string file) : inputFile(file)
{
	//CATCH EXCEPTION HERE TO ALLOW ERRORS IN MAIN
	try
	{
		this->parseData();
	}
	catch(const std::exception& e)
	{
		this->btcMap.clear();
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->inputFile = src.inputFile;
	this->btcMap = src.btcMap;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->btcMap.clear();
		this->btcMap = src.btcMap;
		this->inputFile = src.inputFile;
	}
	return *this;
}

//METHODS
void BitcoinExchange::parseData()
{
    std::string		line;
    std::ifstream	file(this->inputFile);
	
    if (file.fail())
        throw FileException();
    std::getline(file, line);
    while (std::getline(file, line))
	{
		//SUBSTR DATE
        std::string date = line.substr(0, 10);
        //SUBSTR VALUE
		std::string value = line.substr(11, line.length());
		//CHECK DATA
        if (date.length() != 10 || value.empty())
		{
            this->btcMap.clear();
            std::cout << "Error: bad input => " << line << std::endl;
            break ;
        }
        if (!BitcoinExchange::checkDbDate(date) || !BitcoinExchange::checkDbValue(value))
		{
            this->btcMap.clear();
            std::cout << "Error: bad input => " << line << std::endl;
            break ;
        }
		//INSERT INTO MAP WITH MAKE PAIR TO AVOID OVERWRITE
		btcMap.insert(std::make_pair(date, std::stod(value)));
    }
    file.close();
}

double BitcoinExchange::getValue(std::string date, std::string quantity) const
{
    std::map<std::string, double>::const_iterator it = btcMap.upper_bound(date);
    if (it == btcMap.begin())
        return 0;

    --it;

    double qt = std::stod(quantity);
    return qt * it->second;
}


//main parsing 
bool BitcoinExchange::checkDbDate(std::string date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (((month == 2 && day > 29) || (month == 4 || month == 6 || month == 9 || month == 11)) && day > 30)
        return false;

    return true;
}

//check error
bool BitcoinExchange::checkDbValue(std::string value_str)
{
    size_t pos;
    double value_db = std::stod(value_str, &pos);
    return pos == value_str.size() && value_db >= 0;
}


//error check
const std::string	BitcoinExchange::checkFileValue(std::string value_str)
{
	char		*remain = NULL;
	double		value_db = strtod(value_str.c_str(), &remain);
	std::string	remain_str(remain);
	
	if (!remain_str.empty())
		return ("Error: not a number");
	if (value_db < 0)
		return ("Error: not a positive number.");
	if (value_db >= 2147483648)
		return ("Error: too large a number.");
	return ("VALID");
}

//EXCEPTIONS
const char* BitcoinExchange::FileException::what() const throw()
{
	return ("Error: couldn't open file.");
}
