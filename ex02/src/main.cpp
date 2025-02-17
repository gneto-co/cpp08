#include "../includes/MutantStack.hpp"

/* SECTION - press_any_key() */

#include <termios.h>
#include <unistd.h>
void press_any_key()
{
	PRINT << LOW_BRIGHT << "Press any key ( )" << CURSOR_LEFT(2);

	struct termios old_terminal, newt;
	tcgetattr(STDIN_FILENO, &old_terminal);
	newt = old_terminal;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	char c = getchar();
	if (!std::isprint(c))
		c = ' ';
	PRINT << c << CURSOR_RIGHT(1) << RESEND;

	tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
}

/* !SECTION */

/* SECTION - functions */

template <typename Iterator>
void print_container(Iterator it_start, Iterator it_end)
{
	while (it_start != it_end)
	{
		PRINT << BLUE << *it_start << RESEND;
		++it_start;
	}
}

/* !SECTION */

/* SECTION - main() */

int main()
{
	MAIN_MSG("Mutant Stack Declaration")
	MutantStack<int> mt;
	SPACER(1)

	{
		MAIN_MSG("top(), size()")
		mt.push(4);
		mt.push(2);

		PRINT << BLUE "Top: " << mt.top() << RESEND;
		PRINT << BLUE "Size: " << mt.size() << RESEND;

		press_any_key();
		SPACER(1)
	}

	{
		MAIN_MSG("pop()")
		mt.pop();

		PRINT << BLUE "Top: " << mt.top() << RESEND;
		PRINT << BLUE "Size: " << mt.size() << RESEND;

		press_any_key();
		SPACER(1)
	}

	mt.push(2);
	mt.push(42);
	mt.push(24);
	MutantStack<int>::iterator it_begin = mt.begin();
	MutantStack<int>::iterator it_end = mt.end();

	{
		MAIN_MSG("print_container() iterator")
		print_container(it_begin, it_end);

		press_any_key();
		SPACER(1)
	}

	{
		MAIN_MSG("sort() iterator")
		std::sort(it_begin, it_end);
		print_container(it_begin, it_end);

		press_any_key();
		SPACER(1)
	}

	MutantStack<int>::reverse_iterator rit_begin = mt.rbegin();
	MutantStack<int>::reverse_iterator rit_end = mt.rend();

	{
		MAIN_MSG("print_container() reverse_iterator")
		print_container(rit_begin, rit_end);

		press_any_key();
		SPACER(1)
	}

	{
		MAIN_MSG("sort() reverse_iterator")
		std::sort(rit_begin, rit_end);
		print_container(rit_begin, rit_end);

		press_any_key();
		SPACER(1)
	}

	{
		MAIN_MSG("print_container() iterator")
		print_container(it_begin, it_end);

		press_any_key();
		SPACER(1)
	}

	MutantStack<int> mt2(mt);
	MutantStack<int>::iterator it2_begin = mt2.begin();
	MutantStack<int>::iterator it2_end = mt2.end();
	{
		MAIN_MSG("copy teste")

		print_container(it2_begin, it2_end);

		press_any_key();
		SPACER(1)
	}

	return (0);
}

/* !SECTION */
