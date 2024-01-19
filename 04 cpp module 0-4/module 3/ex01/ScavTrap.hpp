/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:28:23 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/19 14:55:00 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
    // Private variables

public:
    // Constructors
            ScavTrap( void );
            ScavTrap( std::string name );
		    ScavTrap( const ScavTrap& cpy );

    // Destructor
            ~ScavTrap( void );
            
    // Operators
	    	ScavTrap& operator=( const ScavTrap& cpy );

    // Member functions
    void    setData( void );
    void	guardGate( void );
    void    attack( const std::string& target );
};
 