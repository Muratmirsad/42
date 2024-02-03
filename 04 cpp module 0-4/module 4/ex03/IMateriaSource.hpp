/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:02:38 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:47:51 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource
{
public:
                        IMateriaSource( void );
                        IMateriaSource( const IMateriaSource& cpy );
    
    virtual             ~IMateriaSource( void );
    virtual void        learnMateria(AMateria *m) = 0;
    virtual AMateria    *createMateria(std::string const &type) = 0;
    IMateriaSource      &operator=( const IMateriaSource& cpy );
};
