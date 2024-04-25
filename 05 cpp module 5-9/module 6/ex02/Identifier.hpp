#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include "Base.hpp"

class Identifier {
	public:
		static void identify(Base* p);
		static void identify(Base& p);
};

#endif