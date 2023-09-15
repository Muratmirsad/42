#pragma once

#include <fstream>
#include <iostream>

class replace
{
private:
    std::ifstream   inFile;
    std::ofstream   outFile;
    std::string     s1;
    std::string     s2;

public:
    replace(std::string fileName, std::string avS1, std::string avS2);
    ~replace();

    void    findAndWrite();
};