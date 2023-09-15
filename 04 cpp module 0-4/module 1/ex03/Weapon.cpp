/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:34:47 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/15 16:22:42 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string tmp)
{
	setType(tmp);
}

Weapon::Weapon()
{
	
}

Weapon::~Weapon()
{
	
}

const std::string	&Weapon::getType()
{
    return this->_type;
}

void	Weapon::setType(std::string _newType)
{
	this->_type = _newType;
}
