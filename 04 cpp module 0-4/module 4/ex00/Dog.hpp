/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:19:23 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:44:55 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog( void );
        ~Dog( void );
        Dog( const Dog& cpy );

        void    makeSound( void ) const;
        Dog&    operator=( const Dog& cpy );


};