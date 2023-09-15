#pragma once

#include "Weapon.hpp"

class Weapon;

class HumanB
{
private:
    std::string _name;
    Weapon      *_weapon;

public:
    HumanB(std::string tmpName);

    void    attack(void);
    void	setWeapon(Weapon &newWeapon);

    ~HumanB(void);
};
