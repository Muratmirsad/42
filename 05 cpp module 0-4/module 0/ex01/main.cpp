/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:53:22 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/22 01:43:04 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	command;

	std::cout << "Commands: ADD, SEARCH and EXIT." << std::endl;
	while (1)
	{
		std::cout << "Enter a command > ";
		std::cin >> command;
		if (command == "ADD")
			book.phonebookAddContact();
		else if (command == "SEARCH")
			book.phonebookListContact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "command not found (try \"HELP\")" << std::endl;
	}
	std::cout << "Exiting..." << std::endl;
	return (0);
}