/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:49:10 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/04 11:18:12 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
    const Fixed &max( const Fixed &var1, const Fixed &var2 );
    const Fixed &min( const Fixed &var1, const Fixed &var2 );
    Fixed       &max( Fixed &o1, Fixed &o2 );
    Fixed       &min( Fixed &o1, Fixed &o2 );
};