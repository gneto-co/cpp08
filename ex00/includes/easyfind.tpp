#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "Strings.h"
#include "easyfind.hpp"

/* SECTION - template funtions */

template <typename T>
typename T::iterator easyfind(T container, int nb)
{
    typename T::iterator it;

	it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

/* !SECTION */

#endif