/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:49:06 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:53:35 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
                        WrongCat( void );
                        ~WrongCat( void );
                        WrongCat( const WrongCat& cpy );

        WrongCat&       operator=( const WrongCat& cpy );
        void            makeSound( void ) const;
};