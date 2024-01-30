/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:49:52 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 15:49:06 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "Some wrong cat sound" << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy)
{
	*this = cpy;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& cpy)
{
	std::cout << "WrongCat copy operator called" << std::endl;
	(void)cpy;
	return (*this);
}