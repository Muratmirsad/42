/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:08:30 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/13 15:06:16 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string tmpName, Weapon tmpWeapon)
{
    this->_name = tmpName;
    this->_weapon = tmpWeapon;
}

HumanA::~HumanA()
{
	
}

void    HumanA::attack(void)
{
	std::cout	<< this->_name
				<< " attacks with their "
				<< this->_weapon.getType()
				<< std::endl;
}