#include "BitcoinExchange.hpp"

void BitcoinExchange::loadDatabase(const std::string& file)
{
    std::ifstream in(file.c_str());

    if (!in)
    {
        std::cerr << "Error: could not open database." << std::endl;
        exit(1);
    }

    std::string line;

    getline(in, line);

    while (getline(in, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string rate;

        getline(ss, date, ',');
        getline(ss, rate);

        _db[date] = atof(rate.c_str());
    }
}

bool BitcoinExchange::validDate(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 0)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::validValue(const std::string& value)
{
    double v = atof(value.c_str());

    if (v < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (v > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

double BitcoinExchange::getRate(const std::string& date)
{
    std::map<std::string, double>::iterator it;

    it = _db.lower_bound(date);

    if (it != _db.end() && it->first == date)
        return it->second;

    if (it == _db.begin())
        return it->second;

    --it;

    return it->second;
}

void BitcoinExchange::processInput(const std::string& file)
{
    std::ifstream in(file.c_str());

    if (!in)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    getline(in, line);

    while (getline(in, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string value;

        if (!getline(ss, date, '|') || !getline(ss, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        while (date[0] == ' ')
            date.erase(0, 1);

        while (date[date.size() - 1] == ' ')
            date.erase(date.size() - 1);

        while (value[0] == ' ')
            value.erase(0, 1);

        while (value[value.size() - 1] == ' ')
            value.erase(value.size() - 1);

        if (!validDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!validValue(value))
            continue;

        double val = atof(value.c_str());

        double rate = getRate(date);

        std::cout << date
                  << " => "
                  << val
                  << " = "
                  << val * rate
                  << std::endl;
    }
}