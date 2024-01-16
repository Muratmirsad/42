/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:49:10 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/16 15:13:34 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <math.h>

class Fixed
{
private:
    int               value;
    static const int  bits = 8;

public:
                Fixed();
                Fixed( const Fixed &cpy );
                Fixed( const int value );
                Fixed( const float float_value );
                ~Fixed();
    Fixed&      operator=( const Fixed &cpy );
    int         getRawBits( void );
    void        setRawBits( int const raw );
    int		    toInt( void ) const;
    float	    toFloat( void ) const;
    bool	    operator==( const Fixed &fixed );
    bool	    operator!=( const Fixed &fixed );
    Fixed	    operator+( const Fixed &fixed );
    Fixed       operator-( const Fixed &fixed );
    bool	    operator<( const Fixed &fixed );
    bool	    operator>( const Fixed &fixed );
    bool        operator<=( const Fixed &fixed );
    bool	    operator>=( const Fixed &fixed );
    Fixed	    operator*( const Fixed &fixed );
    Fixed       operator/( const Fixed &fixed );
    Fixed&      operator++();
    Fixed       operator++( int );
    Fixed&      operator--();
    Fixed       operator--( int );
    static const Fixed &max( const Fixed &a, const Fixed &b );
    static const Fixed &min( const Fixed &a, const Fixed &b );
    static Fixed       &max( Fixed &a, Fixed &b );
    static Fixed       &min( Fixed &a, Fixed &b );
};

std::ostream&	operator<<(std::ostream& os, const Fixed &fixed);