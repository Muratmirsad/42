/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 03:37:49 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/24 05:01:39 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string newName);
void randomChump(std::string newName);

int	main()
{
	Zombie	*tmp;

	tmp = newZombie("1");
	tmp->announce();
	randomChump("2");

	delete tmp;
	return 0;
}