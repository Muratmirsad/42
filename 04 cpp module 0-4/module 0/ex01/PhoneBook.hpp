/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:16:32 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/19 17:32:28 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contact[8];
	int		index;

public:
	PhoneBook();


	void	phonebookAddContact();
	void	phonebookListContact();
	void	put_contact(int index);
	
	~PhoneBook();
};

#endif