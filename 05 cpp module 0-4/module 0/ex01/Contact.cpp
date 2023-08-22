/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:07:02 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/22 12:09:59 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(/* args */)
{
	// setName("");
	// setSurname("");
	// setNickname("");
	// setPhone(0);
	// setSecret("");
	
	//std::cout << "Contact default constructor called" << std::endl;
}

Contact::~Contact()
{
	//std::cout << "Contact destructor called" << std::endl;
}

std::string Contact::getName()
{
	return this->name;
}

std::string Contact::getSurname()
{
	return this->surname;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getPhone()
{
	return this->phone;
}

std::string Contact::getSecret()
{
	return this->secret;
}

void Contact::setName(std::string newName)
{
	this->name = newName;
}

void Contact::setSurname(std::string newSurname)
{
	this->surname = newSurname;
}

void Contact::setNickname(std::string newNicname)
{
	this->nickname = newNicname;
}

void Contact::setPhone(std::string newPhone)
{
	this->phone = newPhone;
}

void Contact::setSecret(std::string newSecret)
{
	this->secret = newSecret;
}