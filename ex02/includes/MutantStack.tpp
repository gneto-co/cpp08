#include "MutantStack.hpp"

/* SECTION - constructors destructors */

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    FT_MSG("MutantStack() Constructor")
    return;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack *copy) : std::stack<T>()
{
    FT_MSG("MutantStack(MutantStack copy) Constructor")
    return;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    FT_MSG("MutantStack() Destructor")
    return;
}

/* !SECTION */

/* SECTION - overload operators */

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    if (this != &src)
    {
        std::stack<T>::operator=(src);
    }
    return *this;
}

/* !SECTION */

/* SECTION - methods */

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}

/* !SECTION */

/* SECTION - exceptions */

/* !SECTION */