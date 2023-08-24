/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:41:58 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/22 23:19:29 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

std::string	phonebookAddHelper(std::string message)
{
	std::string	input;

	while (1)
	{
		std::cout << message;
		std::getline(std::cin, input);	
		if (input.empty())
			continue ;
		else
			return (input);
	}
}

void	PhoneBook::phonebookAddContact()
{
	std::string	input;

	this->contact5.setName(this->contact4.getName());
	this->contact4.setName(this->contact3.getName());
	this->contact3.setName(this->contact2.getName());
	this->contact2.setName(this->contact1.getName());
	
	this->contact5.setSurname(this->contact4.getSurname());
	this->contact4.setSurname(this->contact3.getSurname());
	this->contact3.setSurname(this->contact2.getSurname());
	this->contact2.setSurname(this->contact1.getSurname());

	this->contact5.setPhone(this->contact4.getPhone());
	this->contact4.setPhone(this->contact3.getPhone());
	this->contact3.setPhone(this->contact2.getPhone());
	this->contact2.setPhone(this->contact1.getPhone());

	this->contact5.setNickname(this->contact4.getNickname());
	this->contact4.setNickname(this->contact3.getNickname());
	this->contact3.setNickname(this->contact2.getNickname());
	this->contact2.setNickname(this->contact1.getNickname());

	this->contact5.setSecret(this->contact4.getSecret());
	this->contact4.setSecret(this->contact3.getSecret());
	this->contact3.setSecret(this->contact2.getSecret());
	this->contact2.setSecret(this->contact1.getSecret());

	input = phonebookAddHelper("Enter a name: ");
	this->contact1.setName(input);
	input = phonebookAddHelper("Enter a surname: ");
	this->contact1.setSurname(input);
	input = phonebookAddHelper("Enter a phone number: ");
	this->contact1.setPhone(input);
	input = phonebookAddHelper("Enter a nickname: ");
	this->contact1.setNickname(input);
	input = phonebookAddHelper("Enter a secret: ");
	this->contact1.setSecret(input);
}

void	put_list(Contact tmp)
{
	std::string	tmpArray[4];
	int			len;

	tmpArray[0] = tmp.getName();
	tmpArray[1] = tmp.getSurname();
	tmpArray[2] = tmp.getNickname();
	tmpArray[3] = tmp.getSecret();

	for (int j = 0; j < 4; j++)
	{
		len = tmpArray[j].length();
		for (int i = 0; i < 10; i++)
		{
			if (len > 10 && i == 9)
			{
				std::cout << ".";
				break ;
			}
			std::cout << tmpArray[j][i];
		}
		while (len ++ < 10)
			std::cout << " ";
		if (j != 3)
			std::cout << "\t|\t";
	}
	std::cout << std::endl;
}

void	put_contact(Contact tmp)
{
	std::cout << std::endl << tmp.getName() << "\t|\t";
	std::cout << tmp.getName() << "\t|\t";
	std::cout << tmp.getName() << "\t|\t";
	std::cout << tmp.getName() << "\t|\t";
	std::cout << tmp.getName() << std::endl << std::endl;
}

void	PhoneBook::phonebookListContact()
{
	int	input;
	
	std::cout << std::endl << "1 |\t";
	put_list(this->contact1);
	std::cout << "2 |\t";
	put_list(this->contact2);
	std::cout << "3 |\t";
	put_list(this->contact3);
	std::cout << "4 |\t";
	put_list(this->contact4);
	std::cout << "5 |\t";
	put_list(this->contact5);

	while (1){
		std::cout << "Enter the index of the contact you want to view: ";
		std::cin >> input;
		if (input == 1)
			put_contact(this->contact1);
		else if (input == 2)
			put_contact(this->contact2);
		else if (input == 3)
			put_contact(this->contact3);
		else if (input == 4)
			put_contact(this->contact4);
		else if (input == 5)
			put_contact(this->contact5);
		else{
			std::cout << "Wrong input" << std::endl;
			continue;
	}
	break ;
	}
		
}