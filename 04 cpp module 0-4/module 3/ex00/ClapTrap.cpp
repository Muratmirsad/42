/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:21:47 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/04 11:41:01 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->_hitPoints = 10;
    this->_energyPoints = 10;
}

ClapTrap::~ClapTrap()
{
    
}

void    ClapTrap::attack( const std::string& target )
{
    std::cout << "ClapTrap " << <name> << " attacks " << target << ", causing " << <damage> << " points of damage!"
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    
}
