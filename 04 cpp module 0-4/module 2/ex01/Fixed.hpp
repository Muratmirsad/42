/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:48:54 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/02 12:26:35 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
				Fixed();
				Fixed(const int value);
				Fixed(const float float_value);
				~Fixed();
				Fixed(const Fixed &cpy);
		Fixed&	operator=(const Fixed &cpy);
		int		getRawBits(void);
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream& os, const Fixed &fixed);