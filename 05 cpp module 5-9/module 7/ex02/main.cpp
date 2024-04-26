#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> intArray(5);

    for (size_t i = 0; i < intArray.size(); ++i)
	{
        intArray[i] = i * 10;
    }

    std::cout << "Array elements: ";
    for (size_t i = 0; i < intArray.size(); ++i)
	{
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    try
	{
        int value = intArray[10];
		(void)value;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
