#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _db;
    public:
        void loadDatabase(const std::string& file);
        void processInput(const std::string& file);

        bool validDate(const std::string& date);
        bool validValue(const std::string& value);

        double getRate(const std::string& date);
};

#endif