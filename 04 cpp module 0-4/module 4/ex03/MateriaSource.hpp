/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:57:40 by mdiraga           #+#    #+#             */
/*   Updated: 2024/02/01 11:34:40 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria    *learnedMaterias[4];
    int         learnedCount;

public:
                    MateriaSource( void );
                    MateriaSource( const MateriaSource& cpy );
                    ~MateriaSource( void );

    void            learnMateria( AMateria *m) ;
    AMateria        *createMateria( std::string const &type );
    MateriaSource   &operator=( const MateriaSource& cpy );
};