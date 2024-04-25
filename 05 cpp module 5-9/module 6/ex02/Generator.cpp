#include "Generator.hpp"
#include "a.hpp"
#include "b.hpp"
#include "c.hpp"
#include <cstdlib>

#include <iostream>

Base* Generator::generate() {
	std::srand(std::time(0));
    int random = std::rand() % 3;

    if (random == 0)
	{
        return new A();
	}
    else if (random == 1)
	{
        return new B();
	}
    else
	{
        return new C();
	}
}
