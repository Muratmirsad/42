/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:19:23 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 16:57:58 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
    Brain   *_brain;

    public:
        Dog( void );
        ~Dog( void );
        Dog( const Dog& cpy );

    Dog&    operator=( const Dog& cpy );
    Brain*  getBrain( void ) const;
    void    makeSound( void ) const;
};