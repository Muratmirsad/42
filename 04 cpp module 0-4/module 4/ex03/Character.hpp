/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:11:53 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:04:01 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria    *inventory[4];

public:
                        Character( std::string name );
                        Character( const Character& cpy );
                        ~Character( void );

    std::string const   &getName( void ) const;
    void                equip( AMateria *m );
    void                unequip( int idx );
    void                use( int idx, ICharacter &target );
    Character           &operator=( const Character& cpy );
};