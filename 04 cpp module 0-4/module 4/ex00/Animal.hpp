/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:08:34 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:43:23 by mdiraga          ###   ########.fr       */
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
                        Animal(const Animal& cpy);
        virtual         ~Animal( void );
        std::string     getType( void ) const;
        virtual void    makeSound( void ) const;
        Animal&         operator=(const Animal& cpy);
};