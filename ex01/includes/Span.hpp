#ifndef SPAN_HPP
#define SPAN_HPP

#include "Strings.h"

#include <algorithm>
#include <exception>
#include <vector>

class Span
{
private:
	/* attributes */
	std::vector<int> _vec;
	unsigned int _size;

public:
	/* constructors destructors */
	Span();
	Span(unsigned int size);
	Span(const Span *copy);

	/* operators */
	Span &operator=(const Span &src);

	/* methods */
	void addNumber(int nb);
	void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
	int shortestSpan() const;
	int longestSpan() const;

	/* exceptions */
	class AlreadyFullContainerException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NonComparableContainerException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif