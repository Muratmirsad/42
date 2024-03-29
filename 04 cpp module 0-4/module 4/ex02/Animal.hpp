/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:08:34 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:54:37 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {
    protected:
        std::string type;

    public:
                        Animal( void );
                        Animal(std::string animalType);
        virtual         ~Animal( void );
                        Animal(const Animal& cpy);

        Animal&         operator=(const Animal& cpy);
        std::string     getType( void ) const;
        virtual void    makeSound( void ) const = 0;
};