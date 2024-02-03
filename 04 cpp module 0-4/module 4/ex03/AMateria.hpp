/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:15:35 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:42:16 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
                        AMateria( void );
                        AMateria( std::string const &type );
                        AMateria( const AMateria& cpy );
    virtual             ~AMateria( void );

    std::string const   &getType( void ) const;
    virtual AMateria    *clone( void ) const = 0;
    virtual void        use( ICharacter &target );
    AMateria&           operator=( const AMateria& cpy );
};