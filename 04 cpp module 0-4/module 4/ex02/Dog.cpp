/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:19:28 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 17:00:15 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

void Dog::makeSound( void ) const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog::Dog( const Dog& cpy )
{
	*this = cpy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&    Dog::operator=( const Dog& cpy )
{
	std::cout << "Dog copy operator called" << std::endl;
	this->type = cpy.type;
	(this->_brain) = new Brain(*(cpy._brain));
	return *this;
}
Brain*  Dog::getBrain( void ) const
{
    return this->_brain;
}