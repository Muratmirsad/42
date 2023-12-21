/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:23:46 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/21 17:23:47 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
