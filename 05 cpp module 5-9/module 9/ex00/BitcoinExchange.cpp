#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string _fileName)
{
    readData(_fileName);
}

BitcoinExchange::~BitcoinExchange()
{

}


void BitcoinExchange::readData(std::string _fileName)
{
  std::ifstream inputFile(_fileName);
  std::ifstream dataFile("data.csv");

  if (inputFile.is_open() && dataFile.is_open())
  {
    std::string rawData;
    getline(inputFile, rawData);
    getline(dataFile, rawData);

    // data.csv update
    while (getline(dataFile, rawData))
    {
      addDataBase(rawData);
    }

    // input.txt
    while (getline(inputFile, rawData))
    {
      if (dataCheck(rawData))
      {
        std::string date;
        double inputValue;
        extractDateAndValue(rawData, date, inputValue);

        // data find
        std::map<std::string, double>::const_iterator dataIt = _data.find(date);
        if (dataIt != _data.end())
        {
          double dataValue = dataIt->second;
          std::cout << date << " => " << inputValue * dataValue << std::endl;
        }
        else
        {
          dataIt = _data.lower_bound(date);
          if (dataIt != _data.begin())
          {
            --dataIt;
            double dataValue = dataIt->second;
            std::cout << date << " => " << inputValue * dataValue << std::endl;
          }
          else
          {
            std::cout << date << " => Date not found" << std::endl;
          }
        }
      }
      else
      {
        std::cout << "Error: Invalid data format" << std::endl;
      }
    }

    inputFile.close();
    dataFile.close();
  }
  else
  {
    std::cout << "Error: File could not be opened" << std::endl;
  }
}

void BitcoinExchange::extractDateAndValue(const std::string& rawData, std::string& date, double& value)
{
  size_t pos = rawData.find("|");
  date = rawData.substr(0, pos - 1);
  value = std::atof(rawData.substr(pos + 2).c_str());
}

void    BitcoinExchange::addDataBase(std::string rawData)
{
    double  tmp;

    size_t bracket = rawData.find(",");

    tmp = std::atof(rawData.substr(bracket + 1).c_str());
    this->_data[rawData.substr(0, bracket)] = tmp;
}

bool BitcoinExchange::dataCheck(std::string rawData)
{
    std::string year, month, day;
    int i = 0, j = 0;

    while (rawData[i] == ' ')
        i++;

    while (isdigit(rawData[i]))
        i++, j++;

    if (j != 4 || rawData[i] != '-')
        return false;

    year = rawData.substr(i - 4, i - 1);
    
    j = 0, i++;

    while (isdigit(rawData[i]))
        i++, j++;

    if (j != 2 || rawData[i] != '-')
        return false;

    month = rawData.substr(i - 2, i - 1);

    j = 0, i++;
    
    while (isdigit(rawData[i]))
        i++, j++;

    if (j != 2 || rawData[i] != ' ' || rawData[i + 1] != '|' || rawData[i + 2] != ' ')
        return false;

    day = rawData.substr(i - 2, i - 1);

    j = 0, i += 3;

    while (isdigit(rawData[i]))
        i++;
    
    if (rawData[i] == '.' && j <= 1)
        j++, i++;

    while (isdigit(rawData[i]))
        i++;

    while (rawData[i] == ' ')
        i++;

    if (rawData[i] == '\0' && checkDay(std::atoi(year.c_str()), std::atoi(month.c_str()) , std::atoi(day.c_str())))
        return true;

    return false;
}

bool BitcoinExchange::checkDay(int year, int month, int day)
{
    if (month < 1 || month > 12 || day < 1 || year < 1)
        return false;

    if (month == 2) {
        // Check for February
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            // Leap year
            return day <= 29;
        } else {
            // Non-leap year
            return day <= 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        // Months with 30 days
        return day <= 30;
    } else {
        // Months with 31 days
        return day <= 31;
    }
}
