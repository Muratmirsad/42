/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:06:04 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:23:05 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
                Ice( void );
                Ice( const Ice& cpy );

    AMateria    *clone() const;
    void        use(ICharacter &target);
    Ice&        operator=( const Ice& cpy );
};