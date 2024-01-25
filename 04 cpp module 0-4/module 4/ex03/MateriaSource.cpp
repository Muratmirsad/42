/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:58:26 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/25 20:25:08 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    for (int i = 0; i < 4; ++i)
    {
        learnedMaterias[i] = nullptr;
    }
}

MateriaSource::~MateriaSource( void )
{
    for (int i = 0; i < 4; ++i)
    {
        delete learnedMaterias[i];
    }
}

void    MateriaSource::learnMateria( AMateria *m )
{
    if (learnedCount < 4)
    {
        learnedMaterias[learnedCount++] = m->clone();
    }
}

AMateria*   MateriaSource::createMateria( std::string const &type )
{
    for (int i = 0; i < this->learnedCount; ++i)
    {
        if (this->learnedMaterias[i]->getType() == type)
        {
            return this->learnedMaterias[i]->clone();
        }
    }
    return nullptr;
}