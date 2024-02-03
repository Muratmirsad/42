/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:09:58 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:45:06 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
}

Cure&    Cure::operator=( const Cure& cpy )
{
	(void)cpy;
	std::cout << "Cure copy operator called" << std::endl;
	return *this;
}

Cure::Cure( const Cure& cpy )
{
	std::cout << "Cure copy constructor called" << std::endl;
	(void)cpy;
}