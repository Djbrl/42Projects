#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <string>
# include <map>
# include <iostream>
# include <fstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double>	btcMap;
        std::string						inputFile;
        void							parseData();
        BitcoinExchange();

    public:
        //UTILS
        BitcoinExchange(std::string file);
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange(void);
        BitcoinExchange &operator=(BitcoinExchange const &src);
        //METHODS        
        static bool		            checkDbDate(std::string date);
        static bool		            checkDbValue(std::string value_str);
        static const std::string    checkFileValue(std::string value_str);
        double                      getValue(std::string date, std::string quantity) const;
        //EXCEPTIONS
        class FileException : public std::exception{
            public:
                const char* what() const throw();
        };
};

#endif