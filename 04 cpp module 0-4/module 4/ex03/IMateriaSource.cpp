/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:03:20 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:48:15 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

IMateriaSource::IMateriaSource( void )
{
	std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::~IMateriaSource( void )
{
	std::cout << "IMateriaSource destructor called" << std::endl;
}

IMateriaSource&    IMateriaSource::operator=( const IMateriaSource& cpy )
{
	(void)cpy;
	std::cout << "IMateriaSource copy operator called" << std::endl;
	return *this;
}

IMateriaSource::IMateriaSource( const IMateriaSource& cpy )
{
	(void)cpy;
	std::cout << "IMateriaSource copy constructor called" << std::endl;
}