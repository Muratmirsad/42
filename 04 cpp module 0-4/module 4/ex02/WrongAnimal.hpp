/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:44:27 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:57:59 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
    public:
                        WrongAnimal( void );
                        ~WrongAnimal( void );
                        WrongAnimal(const WrongAnimal& cpy);

        WrongAnimal&    operator=(const WrongAnimal& cpy);
        void            makeSound( void ) const;

};