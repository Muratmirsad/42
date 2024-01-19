/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:20:50 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/19 13:27:06 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
protected:
    // Protected variables
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

public:
    // Constructors
            ClapTrap( void );
            ClapTrap( std::string name );
		    ClapTrap( const ClapTrap& cpy );

    // Destructor
            ~ClapTrap( void );
            
    // Overloaded operators
	ClapTrap& operator=( const ClapTrap& cpy );

    // Member functions
    void    printData( void );
    void    setData( int hitPoints, int energyPoints, int attackDamage );
    void    attack( const std::string& target );
    void    takeDamage( unsigned int amount );
    void    beRepaired( unsigned int amount );
};
 