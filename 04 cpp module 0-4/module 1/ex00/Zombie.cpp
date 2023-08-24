/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 03:39:12 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/24 04:53:22 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "ZOMBIE";
}
Zombie::~Zombie()
{

}

std::string	Zombie::getName()
{
	return this->name;
}

void	Zombie::setName(std::string newName)
{
	this->name = newName;
}

void	Zombie::announce(void)
{
	std::cout << this->name << "\t" << "BraiiiiiiinnnzzzZ..." << std::endl;
}
