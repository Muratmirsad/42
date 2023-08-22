/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:41:58 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/22 12:33:04 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::phonebookAddContact()
{
	std::string	tmp;

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

	std::cout << "Enter a name: ";
	std::cin >> tmp;
	this->contact1.setName(tmp);
	std::cout << "Enter a surname: ";
	std::cin >> tmp;
	this->contact1.setSurname(tmp);
	std::cout << "Enter a phone number: ";
	std::cin >> tmp;
	this->contact1.setPhone(tmp);
	std::cout << "Enter a nickname: ";
	std::cin >> tmp;
	this->contact1.setNickname(tmp);
	std::cout << "Enter a secret: ";
	std::cin >> tmp;
	this->contact1.setSecret(tmp);
}

void	put_list(Contact tmp)
{
	std::string	tmpArray[5];
	int			len;

	tmpArray[0] = tmp.getName();
	tmpArray[1] = tmp.getSurname();
	tmpArray[2] = tmp.getNickname();
	tmpArray[3] = tmp.getPhone();
	tmpArray[4] = tmp.getSecret();

	for (int j = 0; j < 5; j++)
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
		if (j != 4)
			std::cout << "\t\t|\t\t";
	}
	std::cout << std::endl;
}

void	PhoneBook::phonebookListContact()
{
	put_list(this->contact1);
	put_list(this->contact2);
	put_list(this->contact3);
	put_list(this->contact4);
	put_list(this->contact5);
}