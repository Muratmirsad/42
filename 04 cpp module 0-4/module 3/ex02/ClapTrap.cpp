/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:21:47 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/19 13:49:54 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->_name = "Default";
    setData(10, 10, 0);
}

ClapTrap::ClapTrap( std::string name )
{
    std::cout << "Name constructor called" << std::endl;
    this->_name = name;
    setData(10, 10, 0);
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "Default destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& cpy )
{
	this->_attackDamage = cpy._attackDamage;
	this->_name = cpy._name;
	this->_energyPoints = cpy._energyPoints;
	this->_hitPoints = cpy._hitPoints;
	return *this;
}

ClapTrap::ClapTrap( const ClapTrap& cpy )
{
    *this = cpy;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

void    ClapTrap::setData( int hitPoints, int energyPoints, int attackDamage )
{
    this->_hitPoints = hitPoints;
    this->_energyPoints = energyPoints;
    this->_attackDamage = attackDamage;
}

void    ClapTrap::printData( void )
{
    std::cout << "_attackDamage: " << this->_attackDamage << std::endl
                << "_energyPoints: " << this->_energyPoints << std::endl
                << "_hitPoints: " << this->_hitPoints << std::endl;
}

void    ClapTrap::attack( const std::string& target )
{
    if (this->_energyPoints && this->_hitPoints)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints -= 1;
    }
    else
    {
        std::cout << "Not enough energy points!";
    }
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (this->_hitPoints > 0)
    {
        std::cout << "ClapTrap took "<< amount <<" amount of damage!" << std::endl;
        this->_hitPoints -= amount;
        if (this->_hitPoints <= 0)
            std::cout << "ClapTrap is dead!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap is already dead!" << std::endl;
    }
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (this->_energyPoints)
    {
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
        std::cout << "ClapTrap's energy point increased by " << amount << "!" << std::endl;
    }
    else
    {
        std::cout << "Not enough energy points!";
    }
    
}
