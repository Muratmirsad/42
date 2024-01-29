/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:05 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/29 14:29:26 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
    Brain   *_brain;

    public:
            Cat( void );
            ~Cat( void );
            Cat( const Cat& cpy );

    Cat&    operator=( const Cat& cpy );
    Brain*  getBrain( void ) const;
    void    makeSound( void ) const;
};