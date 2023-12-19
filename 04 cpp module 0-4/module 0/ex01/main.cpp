/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:53:22 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/19 16:06:38 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	command;

	std::cout << "Commands: ADD, SEARCH and EXIT." << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, command);
		if (command == "ADD")
			book.phonebookAddContact();
		else if (command == "SEARCH")
			book.phonebookListContact();
		else if (command == "EXIT")
			break ;
		else if (std::cin.eof())
			exit(0);
	}
	std::cout << "Exiting..." << std::endl;
	return (0);
}