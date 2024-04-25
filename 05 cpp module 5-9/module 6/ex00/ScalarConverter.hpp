#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP
#define ERROR -1

#include <iostream>
#include <sstream>
#include <limits>

class ScalarConverter {
    private:
        static void    convertToChar(const char literal);
        static void    convertToInt(const std::string& literal);
        static void    convertToFloat(const std::string& literal);
        static void    convertToDouble(const std::string& literal);

    public:
        static void convert(const std::string& literal);
};

#endif