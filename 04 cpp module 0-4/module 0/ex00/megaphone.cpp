/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:03:35 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/19 15:12:25 by mdiraga          ###   ########.fr       */
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

