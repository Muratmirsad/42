/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:41:58 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/19 18:16:17 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
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

	for (int i = 7; i > 0; i--)
	{
		this->_contact[i].setName(this->_contact[i - 1].getName());
		this->_contact[i].setSurname(this->_contact[i - 1].getSurname());
		this->_contact[i].setPhone(this->_contact[i - 1].getPhone());
		this->_contact[i].setNickname(this->_contact[i - 1].getNickname());
		this->_contact[i].setSecret(this->_contact[i - 1].getSecret());
	}

	input = phonebookAddHelper("Enter a name: ");
	this->_contact[0].setName(input);
	input = phonebookAddHelper("Enter a surname: ");
	this->_contact[0].setSurname(input);
	input = phonebookAddHelper("Enter a phone number: ");
	this->_contact[0].setPhone(input);
	input = phonebookAddHelper("Enter a nickname: ");
	this->_contact[0].setNickname(input);
	input = phonebookAddHelper("Enter a secret: ");
	this->_contact[0].setSecret(input);
	this->index++;
}

void	put_list(Contact tmp, int i)
{
	std::string	tmpArray[4];
	int			len;

	tmpArray[0] = tmp.getName();
	tmpArray[1] = tmp.getSurname();
	tmpArray[2] = tmp.getNickname();

	std::cout << "index: " << i + 1 << " |\t";
	for (int j = 0; j < 3; j++)
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
		while (len++ < 10)
		{
			std::cout << " ";
		}
		if (j != 2)
		{
			std::cout << "\t|\t";
		}
	}
	std::cout << std::endl;
}

void	PhoneBook::put_contact(int index)
{
	std::cout << std::endl << this->_contact[index].getName() << "\t|\t";
	std::cout << this->_contact[index].getSurname() << "\t|\t";
	std::cout << this->_contact[index].getNickname() << "\t|\t";
	std::cout << this->_contact[index].getPhone() << "\t|\t";
	std::cout << this->_contact[index].getSecret() << std::endl << std::endl;
}

void	PhoneBook::phonebookListContact()
{
    int input;

	std::cout << std::endl;
    for (int i = 0; i < 8 && i < index; i++)
    {
        put_list(this->_contact[i], i);
    }
	std::cout << std::endl;

    while (true)
    {
        std::cout << "Enter the index of the contact you want to view: ";
        std::cin >> input;

        if (std::cin.fail() || input < 1 || input > 8)
        {
            std::cout << "Wrong input. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            put_contact(input - 1);
            break;
        }
    }
	std::cin.ignore();
}