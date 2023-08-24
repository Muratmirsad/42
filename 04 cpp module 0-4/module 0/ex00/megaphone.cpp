/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:03:35 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/20 16:35:20 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **ar)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for(int j = 0; ar[i][j] != 0; j++)
			{
				ar[i][j] = std::toupper(ar[i][j]);
			}
		std::cout << ar[i];
		if (i < ac - 1)
			std::cout << ' ';
		}
	}
	std::cout << std::endl;
}
