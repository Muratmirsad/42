#pragma once

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
private:
    std::map<std::string, double> _data;
    std::map<std::string, double> _input;

    void    readData(std::string _fileName);
    void    addDataBase(std::string rawData);
    bool    dataCheck(std::string rawData);
    bool    checkDay(int year, int month, int day);
    void    extractDateAndValue(const std::string& rawData, std::string& date, double& value);

public:
    BitcoinExchange(std::string _fileName);
    ~BitcoinExchange();


};
