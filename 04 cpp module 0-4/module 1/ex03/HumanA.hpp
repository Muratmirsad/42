/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:41:44 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/15 17:42:04 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon      &_weapon;

public:
    HumanA(std::string tmpName, Weapon &tmpWeapon) : _name(tmpName), _weapon(tmpWeapon) {};

    void    attack(void);

    ~HumanA();
};
