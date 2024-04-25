#include "Identifier.hpp"
#include "a.hpp"
#include "b.hpp"
#include "c.hpp"
#include <iostream>

void Identifier::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
	{
        std::cout << "A" << std::endl;
	}
    else if (dynamic_cast<B*>(p))
	{
        std::cout << "B" << std::endl;
	}
    else if (dynamic_cast<C*>(p))
	{
        std::cout << "C" << std::endl;
	}
}

void Identifier::identify(Base& p)
{
    if (typeid(p) == typeid(A))
	{
        std::cout << "A" << std::endl;
	}
    else if (typeid(p) == typeid(B))
	{
        std::cout << "B" << std::endl;
	}
    else if (typeid(p) == typeid(C))
	{
        std::cout << "C" << std::endl;
	}
}
