#pragma once
#include "Weapon.hpp"

class Weapon;

class HumanA
{
private:
    Weapon      _weapon;
    std::string _name;

public:
    HumanA(std::string tmpName, Weapon tmpWeapon);

    void    attack(void);

    ~HumanA();
};
