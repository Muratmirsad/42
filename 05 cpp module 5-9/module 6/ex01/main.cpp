#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;

    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    if (deserialized == &data)
	{
        std::cout << "Serialize and deserialize successfully!" << std::endl;
    } else
	{
        std::cout << "Error: Serialize and deserialize operation failed!" << std::endl;
    }

    return 0;
}