/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:59:50 by mdiraga           #+#    #+#             */
/*   Updated: 2023/10/20 17:35:42 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
    int					_intager;
    static const int	_fracNumber = 8;

public:
    Fixed( void );
    ~Fixed( void );

	// kopyalama kurucusu
	// kopyalama atama operatorunu asiri yukleme
	// yikici
	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
			
};
