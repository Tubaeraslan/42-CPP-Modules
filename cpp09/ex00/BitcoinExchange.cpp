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

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;

    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty file." << std::endl;
        return false;
    }

    if (line != "date,exchange_rate")
    {
        std::cerr << "Error: invalid database header." << std::endl;
        return false;
    }

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string rateStr;

        if (std::getline(ss, date, ',') &&
            std::getline(ss, rateStr))
        {
            double rate = std::atof(rateStr.c_str());
            _database[trim(date)] = rate;
        }
    }

    if (_database.empty())
    {
        std::cerr << "Error: database empty." << std::endl;
        return false;
    }

    file.close();
    return true;
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

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] =
    {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    bool leap =
    (
        (year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0)
    );

    if (leap)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}


bool BitcoinExchange::isValidValue(const std::string& value)
{
    std::stringstream ss(value);
    double number;

    ss >> number;

    if (ss.fail() || !ss.eof())
        return false;

    return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date)
{
    std::map<std::string, double>::iterator it;

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

    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty file." << std::endl;
        return;
    }

    if (line != "date | value")
    {
        std::cerr << "Error: bad header." << std::endl;
        return;
    }

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
                      << line << std::endl;
            continue;
        }

        if (!isValidValue(valueStr))
        {
            std::cerr << "Error: bad input => "
                    << line << std::endl;
            continue;
        }

        double value = std::atof(valueStr.c_str());

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        double rate = getExchangeRate(date);

        if (rate < 0)
        {
            std::cerr << "Error: no rate found." << std::endl;
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