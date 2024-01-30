/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:03 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:43:50 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound( void ) const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Cat&    Cat::operator=( const Cat& cpy )
{
	std::cout << "Cat copy operator called" << std::endl;
	this->type = cpy.type;
	return *this;
}

Cat::Cat( const Cat& cpy )
{
	*this = cpy;
	std::cout << "Cat copy constructor called" << std::endl;
}