/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:28:29 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/19 13:23:22 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    this->_name = "Default";
    setData(100, 50, 20);
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name )
{
    std::cout << "Name constructor called" << std::endl;
    this->_name = name;
    setData(100, 50, 20);
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "Default destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& cpy )
{
	this->_attackDamage = cpy._attackDamage;
	this->_name = cpy._name;
	this->_energyPoints = cpy._energyPoints;
	this->_hitPoints = cpy._hitPoints;

	return *this;
}

ScavTrap::ScavTrap( const ScavTrap& cpy )
{
    *this = cpy;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode!" << std::endl;
}

void    ScavTrap::attack( const std::string& target )
{
    if (this->_energyPoints && this->_hitPoints)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints -= 1;
    }
    else
    {
        std::cout << "Not enough energy points!";
    }
}
