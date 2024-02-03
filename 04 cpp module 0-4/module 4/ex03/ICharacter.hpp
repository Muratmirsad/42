/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:04:18 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:41:11 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
public:
                                ICharacter( void );
                                ICharacter( const ICharacter& cpy );

    virtual                     ~ICharacter( void );
    virtual std::string const   &getName() const = 0;
    virtual void                equip(AMateria *m) = 0;
    virtual void                unequip(int idx) = 0;
    virtual void                use(int idx, ICharacter &target) = 0;
    ICharacter&                 operator=( const ICharacter& cpy );
};