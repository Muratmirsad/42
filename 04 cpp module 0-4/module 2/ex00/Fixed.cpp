/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:17:34 by mdiraga           #+#    #+#             */
/*   Updated: 2023/11/29 17:24:37 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->_intager = 0;
}
 
Fixed::~Fixed(void)
{
    
}

int Fixed::getRawBits( void )
{
	return this->_intager;
}

void	Fixed::setRawBits( int const raw )
{
	this->_intager = raw;
}
