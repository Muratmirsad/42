/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:22:18 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/19 14:52:05 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    this->_name = "Default";
    setData(100, 100, 30);
}

FragTrap::FragTrap( std::string name ): ClapTrap()
{
    std::cout << "Name constructor called" << std::endl;
    this->_name = name;
    setData(100, 100, 30);
}

FragTrap::~FragTrap( void )
{
    std::cout << "Default destructor called" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& cpy )
{
	this->_attackDamage = cpy._attackDamage;
	this->_name = cpy._name;
	this->_energyPoints = cpy._energyPoints;
	this->_hitPoints = cpy._hitPoints;
	return *this;
}

FragTrap::FragTrap( const FragTrap& cpy ): ClapTrap()
{
    *this = cpy;
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

void    FragTrap::highFivesGuys( void )
{
    std::cout << "High five!" << std::endl;
}