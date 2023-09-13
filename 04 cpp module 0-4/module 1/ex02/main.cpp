#include <iostream>

int	main()
{
	std::string	str = "Hello World!";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout	<< "str:\t\t" << &str << std::endl
				<< "stringPTR:\t" << &stringPTR << std::endl
				<< "stringREF:\t" << &stringREF << std::endl;

	std::cout	<< "str:\t\t" << str << std::endl
				<< "stringPTR:\t" << *stringPTR << std::endl
				<< "stringREF:\t" << stringREF << std::endl;
}