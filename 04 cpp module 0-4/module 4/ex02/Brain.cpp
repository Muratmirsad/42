/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:32:43 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 10:35:28 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
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
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}

Brain& Brain::operator=(const Brain& brain)
{
	std::cout << "Brain copy operator called" << std::endl;
	if (this != &brain)
	{
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = brain._ideas[i];
	}
	return (*this);
}