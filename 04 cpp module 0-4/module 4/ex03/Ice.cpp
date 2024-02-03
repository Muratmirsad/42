/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:06:11 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:45:26 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice( void ) : AMateria("ice")
{ 
    std::cout << "Ice default constructor called" << std::endl;
}

AMateria *Ice::clone( void ) const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}

Ice&    Ice::operator=( const Ice& cpy )
{
	(void)cpy;
	std::cout << "Ice copy operator called" << std::endl;
	return *this;
}

Ice::Ice( const Ice& cpy )
{
	(void)cpy;
	std::cout << "Ice copy constructor called" << std::endl;
}