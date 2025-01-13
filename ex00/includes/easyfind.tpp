#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "Strings.h"
#include "easyfind.hpp"

/* SECTION - template funtions */

template <typename Type>
typename Type::iterator easyfind(Type container, int nb)
{
    typename Type::iterator it;

	it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

/* !SECTION */

#endif