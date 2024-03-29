/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 04:33:36 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/13 09:52:48 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string newName)
{
	Zombie	*_newZombie = new Zombie;

	_newZombie->setName(newName);
	return (_newZombie);
}

Zombie*    zombieHorde(int N, std::string name)
{
	Zombie	*arrayZombie = new Zombie[N];

	while (N--)
	{
		arrayZombie[N].setName(name);
	}

	return arrayZombie;
}