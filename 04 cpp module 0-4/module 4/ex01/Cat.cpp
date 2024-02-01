/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:03 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 10:46:35 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat( const Cat& cpy )
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cpy;
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
	(this->_brain) = new Brain(*(cpy._brain));
	return *this;
}

Brain*  Cat::getBrain( void ) const
{
    return this->_brain;
}