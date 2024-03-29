/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:49:23 by mdiraga           #+#    #+#             */
/*   Updated: 2023/11/11 15:49:49 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl		_harl;
    std::string	input;

	std::cout << "Levels; DEBUG, INFO, WARNING and ERROR." << std::endl << "Chose a level > ";
	std::cin >> input;
	_harl.complain(input);
}