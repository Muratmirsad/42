/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:32:43 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 18:25:25 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain constructor called" << std::endl;
    setIdea("default");
}

Brain::~Brain( void )
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string*    Brain::getIdeas( void )
{
	return (this->_ideas);
}

void    Brain::setIdea( std::string idea )
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}

Brain::Brain( const Brain& cpy )
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = cpy;
}

Brain&    Brain::operator=( const Brain& cpy )
{
	std::cout << "Brain copy operator called" << std::endl;
    // (void)cpy;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = cpy._ideas[i];
	return *this;
}