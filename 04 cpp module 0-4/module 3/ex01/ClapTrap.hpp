/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:20:50 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/19 14:54:09 by mdiraga          ###   ########.fr       */
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
    void    setData( void );
    void    printData( void );
    void    attack( const std::string& target );
    void    takeDamage( unsigned int amount );
    void    beRepaired( unsigned int amount );
};
 