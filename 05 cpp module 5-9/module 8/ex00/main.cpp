#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(4);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(9);
    numbers.push_back(2);
    numbers.push_back(6);

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 5);
        std::cout << "5 found, index: " << std::distance(numbers.begin(), it) << std::endl;

        it = easyfind(numbers, 7);
        std::cout << "7 found, index: " << std::distance(numbers.begin(), it) << std::endl; 
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}