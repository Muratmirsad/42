/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:49:06 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 12:59:07 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
                WrongCat();
                ~WrongCat();
                WrongCat( const WrongCat& cpy );

    WrongCat&   operator=( const WrongCat& cpy );
    void        makeSound() const;
};