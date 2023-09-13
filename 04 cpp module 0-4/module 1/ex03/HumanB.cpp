/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:37:28 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/13 16:04:03 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string tmpName)
{
    this->_name = tmpName;
}

HumanB::~HumanB()
{
    
}

void    HumanB::attack(void)
{
	std::cout	<< this->_name
				<< " attacks with their "
				<< this->_weapon.getType()
				<< std::endl;
}

void    HumanB::setWeapon(Weapon newWeapon)
{
    this->_weapon = newWeapon;
}
