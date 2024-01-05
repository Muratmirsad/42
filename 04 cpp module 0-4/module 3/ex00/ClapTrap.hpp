/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:20:50 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/04 11:37:42 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

public:
            ClapTrap();
            ~ClapTrap();
    void    attack( const std::string& target );
    void    takeDamage( unsigned int amount );
    void    beRepaired( unsigned int amount );
};
 