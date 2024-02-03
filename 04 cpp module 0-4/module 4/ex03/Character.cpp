/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:11:56 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:38:56 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character(std::string name) : name(name)
{
    std::cout << "Character name constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        inventory[i] = nullptr;
    }
}

Character::~Character()
{
    std::cout << "Character name destructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        delete inventory[i];
    }
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i] == nullptr)
        {
            inventory[i] = m->clone();
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != nullptr)
    {
        inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != nullptr)
    {
        inventory[idx]->use(target);
    }
}

Character&    Character::operator=( const Character& cpy )
{
	std::cout << "Character copy operator called" << std::endl;
	this->name = cpy.name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = cpy.inventory[i];
	return *this;
}

Character::Character( const Character& cpy )
{
	*this = cpy;
	std::cout << "Character copy constructor called" << std::endl;
}