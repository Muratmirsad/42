#pragma once
#include <iostream>

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string tmpName);
    Weapon();

    const std::string   &getType();
    void                setType(std::string _newType);

    ~Weapon();
};
