/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:41:44 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/14 14:41:45 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

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
