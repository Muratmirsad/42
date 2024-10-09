#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error\n";
		return 1;
	}
	PmergeMe mergeInsert;
	if (!mergeInsert.getNumbers(av))
		return 2;
	std::cout << "Before :   ";
	mergeInsert.printNumbers();
	mergeInsert.sort();
	std::cout << "After  :   ";
	mergeInsert.printNumbers();
	mergeInsert.printInfos();
}