/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:16:32 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/22 16:00:11 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contact1;
	Contact contact2;
	Contact	contact3;
	Contact	contact4;
	Contact	contact5;

public:
	PhoneBook();


	void	phonebookAddContact();
	void	phonebookListContact();
	
	~PhoneBook();
};

#endif