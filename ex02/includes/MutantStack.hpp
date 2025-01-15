#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "Strings.h"

#include <algorithm>
#include <exception>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	/* constructors destructors */
	MutantStack();
	MutantStack(const MutantStack *copy);
	~MutantStack();

	/* operators */
	MutantStack &operator=(const MutantStack &src);

	/* attributes */
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	/* methods */
	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

	/* exceptions */
};

#include "MutantStack.tpp"

#endif