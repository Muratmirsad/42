/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:05 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:44:10 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
    public:
            Cat( void );
            ~Cat( void );
            Cat( const Cat& cpy );

    void    makeSound( void ) const;
    Cat&    operator=( const Cat& cpy );


};