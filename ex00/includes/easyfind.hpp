#ifndef easyfind_HPP
#define easyfind_HPP

#include "Strings.h"

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Number doesn't exist");
	}
};

#endif