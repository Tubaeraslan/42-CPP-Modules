#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);

    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);

    double getExchangeRate(const std::string& date);
};

#endif