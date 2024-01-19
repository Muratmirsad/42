/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:22:10 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/19 13:03:27 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
    
public:
    // Constructors
	            FragTrap();
	            FragTrap(std::string name);
	            FragTrap(const FragTrap& cpy);
    
    // Destructor
	            virtual ~FragTrap();
            
    // Overloaded operators
	FragTrap&	operator=(const FragTrap& cpy);

    // Member functions
	void	    highFivesGuys(void);
};
