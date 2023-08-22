/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:00:15 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/22 01:14:56 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	std::string	name;
	std::string	surname;
	std::string	nickname;
	std::string	phone;
	std::string	secret;

public:
	Contact(/* args */);

	std::string	getName();
	std::string	getSurname();
	std::string	getNickname();
	std::string	getPhone();
	std::string	getSecret();

	void	setName(std::string newName);
	void	setSurname(std::string newSurname);
	void	setNickname(std::string newNickname);
	void	setPhone(std::string newPhone);
	void	setSecret(std::string newSecret);

	~Contact();
};


#endif