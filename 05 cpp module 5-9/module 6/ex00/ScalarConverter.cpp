#include "ScalarConverter.hpp"

void    ScalarConverter::convertToChar(const char literal)
{
    if (literal == ERROR)
    {
        std::cout << "char: conversion not possible" << std::endl;
    }
    else if (std::isprint(literal))
    {
        std::cout << "char: " << literal << std::endl;
    }
    else
    {
        std::cout << "char: non displayable" << std::endl;
    }
}

void    ScalarConverter::convertToInt(const std::string& literal)
{
    try
    {
        std::cout << "int: " << std::stoi(literal) << std::endl;
    }
    catch (...)
    {
        std::cout << "conversion not possible" << std::endl;
    }
}

void    ScalarConverter::convertToFloat(const std::string& literal)
{
    try
    {
        std::cout << "float: " << std::stof(literal) << "f" << std::endl;
    }
    catch (...)
    {
        std::cout << "conversion not possible" << std::endl;
    }
    
}

void    ScalarConverter::convertToDouble(const std::string& literal)
{
    try
    {
        std::cout << "double: " << std::stod(literal) << std::endl;
    }
    catch (...)
    {
        std::cout << "conversion not possible" << std::endl;
    }
    
}

void    ScalarConverter::convert(const std::string& literal)
{
    if (literal.length() != 1)
    {
        convertToChar(ERROR);
    }
    else
    {
        convertToChar(literal[0]);
    }
    convertToInt(literal);
    convertToFloat(literal);
    convertToDouble(literal);
}
