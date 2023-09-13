#pragma once

#include "Weapon.hpp"

class Weapon;

class HumanB
{
private:
    Weapon      _weapon;
    std::string _name;

public:
    HumanB(std::string tmpName);

    void    attack(void);
    void	setWeapon(Weapon newWeapon);

    ~HumanB();
};
