/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:59:50 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/22 15:01:10 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
    int					_value;
	static const int	_bits = 8;

public:
  			Fixed( void );
			Fixed( const Fixed &copy );
   			~Fixed( void );
	Fixed&	operator=( const Fixed &other );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
