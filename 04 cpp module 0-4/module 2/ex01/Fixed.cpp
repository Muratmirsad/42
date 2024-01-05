/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:49:28 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/02 15:08:53 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = cpy.value;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bits;
}

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(float_value * (1 << this->bits));
}

Fixed& Fixed::operator=(const Fixed &cpy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(cpy.value);

    return (*this);
}

int	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

float	Fixed::toFloat(void) const
{
	return (float(this->value) / (1 << this->bits));
}

std::ostream &operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();

	return (os);
}