/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 04:33:40 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/24 04:56:37 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name);

int	main()
{
	Zombie	*tmp;
	int		N = 5;

	tmp = zombieHorde(N, "test");
	while (N--)
	{
		tmp[N].announce();
	}

	delete[] tmp;
	return 0;
}