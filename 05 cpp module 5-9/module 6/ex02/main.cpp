#include "Generator.hpp"
#include "Identifier.hpp"
#include <iostream>

int main()
{
    Base* ptr = Generator::generate();

    Identifier::identify(ptr);
    Identifier::identify(*ptr);

    delete ptr;

    return 0;
}
