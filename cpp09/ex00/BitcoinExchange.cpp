#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

static std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string rateStr;

        if (std::getline(ss, date, ',')
            && std::getline(ss, rateStr))
        {
            float rate = std::atof(rateStr.c_str());

            _database[trim(date)] = rate;
        }
    }

    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;

        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value)
{
    std::stringstream ss(value);

    float number;

    ss >> number;

    if (ss.fail() || !ss.eof())
        return false;

    if (number < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (number > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date)
{
    std::map<std::string, float>::iterator it;

    it = _database.lower_bound(date);

    if (it != _database.end() && it->first == date)
        return it->second;

    if (it != _database.begin())
    {
        --it;
        return it->second;
    }

    return -1;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string valueStr;

        if (!(std::getline(ss, date, '|')
            && std::getline(ss, valueStr)))
        {
            std::cerr << "Error: bad input => "
                      << line << std::endl;
            continue;
        }

        date = trim(date);
        valueStr = trim(valueStr);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => "
                      << date << std::endl;
            continue;
        }

        if (!isValidValue(valueStr))
            continue;

        float value = std::atof(valueStr.c_str());

        float rate = getExchangeRate(date);

        if (rate < 0)
        {
            std::cerr << "Error: no rate found."
                      << std::endl;
            continue;
        }

        std::cout << date
                  << " => "
                  << value
                  << " = "
                  << value * rate
                  << std::endl;
    }

    file.close();
}