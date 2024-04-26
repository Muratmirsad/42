#include "iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original array: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intLength, doubleElement<int>);

    std::cout << "Array after doubling each element: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original array: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl;

    iter(doubleArray, doubleLength, [](double& elem) { elem *= 1.5; });

    std::cout << "Array after scaling each element by 1.5: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl;

    return 0;
}