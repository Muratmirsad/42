/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:23:24 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/21 17:23:25 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	str = "Hello World!";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout	<< "str:\t\t" << &str << "\t" << str << std::endl
				<< "stringPTR:\t" << &stringPTR << "\t" << *stringPTR << std::endl
				<< "stringREF:\t" << &stringREF << "\t" << stringREF << std::endl;
}