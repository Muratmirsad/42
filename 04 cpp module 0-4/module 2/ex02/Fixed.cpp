/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:49:08 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/16 15:05:47 by mdiraga          ###   ########.fr       */
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
	this->value = int(roundf(float_value * (1 << this->bits)));
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

bool	Fixed::operator==(const Fixed &fixed)
{
	std::cout << "== operator called" << std::endl;

	return (this->value == fixed.value);
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	std::cout << "!= operator called" << std::endl;

	return (this->value != fixed.value);
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	std::cout << "+ operator called" << std::endl;
	this->setRawBits(this->value + fixed.value);

	return (*this);
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	std::cout << "- operator called" << std::endl;
	this->setRawBits(this->value - fixed.value);

	return (*this);
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->getRawBits() < fixed.value);
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->getRawBits() > fixed.value);
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->getRawBits() <= fixed.value);
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->getRawBits() >= fixed.value);
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	std::cout << "* operator called" << std::endl;
	this->value = (this->value * fixed.value >> fixed.bits);

	return (*this);
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	std::cout << "/ operator called" << std::endl;
	this->setRawBits(this->value / fixed.value >> fixed.bits);

	return (*this);
}

Fixed& Fixed::operator++()
{
	this->value += 1;

	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->value += 1;

	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->value -= 1;

	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	this->value -= 1;

	return (tmp);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.value > b.value)
		return(a);

	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.value > b.value)
		return(b);

	return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);

	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);

	return (a);
}