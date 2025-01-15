#include "../includes/Span.hpp"

/* SECTION - constructors destructors */

Span::Span() : _size(1)
{
    FT_MSG("Span() Constructor")
    return;
}

Span::Span(unsigned int size) : _size(size)
{
    FT_MSG("Span(unsigned int) Constructor")
    return;
}

Span::Span(const Span *copy)
{
    FT_MSG("Span(Span copy) Constructor")
    *this = copy;
    return;
}

Span::~Span()
{
    FT_MSG("Span() Destructor")
    return;
}

/* !SECTION */

/* SECTION - overload operators */

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->_vec = src._vec;
        this->_size = src._size;
    }

    return *this;
}

/* !SECTION */

/* SECTION - methods */

void Span::addNumber(int nb)
{
    if (_vec.size() < _size)
        _vec.push_back(nb);
    else
        throw AlreadyFullContainerException();
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (_vec.size() + std::distance(start, end) > _size)
		throw AlreadyFullContainerException();
	_vec.insert(_vec.end(), start, end);
}

int Span::longestSpan() const
{
    if (_vec.size() <= 1)
        throw NonComparableContainerException();
    std::vector<int> tmp_vec = _vec;
    std::sort(tmp_vec.begin(), tmp_vec.end());

    return (tmp_vec.back() - tmp_vec.front());
}

int Span::shortestSpan() const
{
    if (_vec.size() <= 1)
        throw NonComparableContainerException();
    std::vector<int> tmp_vec = _vec;
    std::sort(tmp_vec.begin(), tmp_vec.end());

    return (tmp_vec[1] - tmp_vec[0]);
}

/* !SECTION */

/* SECTION - exceptions */

const char *Span::AlreadyFullContainerException::what(void) const throw()
{
    return (RED "Can't add more numbers, container already full" RESET);
}

const char *Span::NonComparableContainerException::what(void) const throw()
{
    return (RED "Container is not comparable, at least 2 numbers are needed" RESET);
}

/* !SECTION */