/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:15:33 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:42:37 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria( void )
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria name constructor called" << std::endl;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria default destructor called" << std::endl;
}

std::string const &AMateria::getType( void ) const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "Default: \"* uses an unspecified skill on " << target.getName() << " *\"" << std::endl;
}

AMateria&    AMateria::operator=( const AMateria& cpy )
{
	std::cout << "AMateria copy operator called" << std::endl;
	this->type = cpy.type;
	return *this;
}

AMateria::AMateria( const AMateria& cpy )
{
	*this = cpy;
	std::cout << "AMateria copy constructor called" << std::endl;
}