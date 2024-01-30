/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:09:52 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:49:24 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
    std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(std::string animalType) : type(animalType)
{
    std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Default animal destructor called for " << type << std::endl;
}

std::string Animal::getType( void ) const
{
    return type;
}

void    Animal::makeSound( void ) const
{
    std::cout << "Some generic animal sound" << std::endl;
}

Animal::Animal( const Animal& cpy )
{
	*this = cpy;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=( const Animal& cpy )
{
	std::cout << "Animal copy operator called" << std::endl;
	this->type = cpy.type;
	return (*this);
}