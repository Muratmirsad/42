/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:09:56 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:44:17 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
                Cure( void );
                Cure( const Cure& cpy );
    
    AMateria    *clone( void ) const;
    void        use(ICharacter &target);
    Cure&       operator=( const Cure& cpy );
};