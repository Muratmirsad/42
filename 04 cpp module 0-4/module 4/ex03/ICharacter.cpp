/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:04:22 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:46:29 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter( void )
{
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::~ICharacter( void )
{
	std::cout << "ICharacter destructor called" << std::endl;
}

ICharacter&    ICharacter::operator=( const ICharacter& cpy )
{
	(void)cpy;
	std::cout << "ICharacter copy operator called" << std::endl;
	return *this;
}

ICharacter::ICharacter( const ICharacter& cpy )
{
	(void)cpy;
	std::cout << "ICharacter copy constructor called" << std::endl;
}