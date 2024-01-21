/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:32:43 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/20 17:39:31 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain constructor called" << std::endl;
    this->_ideas = new std::string[100];
}

Brain::~Brain( void )
{
    std::cout << "Brain destructor called" << std::endl;
    delete this->_ideas;
}
