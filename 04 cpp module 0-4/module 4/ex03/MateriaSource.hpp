/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:57:40 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/24 21:38:40 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *learnedMaterias[4];
    int learnedCount;

public:
    MateriaSource();
    ~MateriaSource();

    void learnMateria( AMateria *m) ;
    AMateria *createMateria( std::string const &type );
};