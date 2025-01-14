#include "../includes/Span.hpp"

// SECTION - press_any_key()

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

//! SECTION

// SECTION - main()

#include <vector>
int main(int, char **)
{
	Span list(5);
	{
		MAIN_MSG("add a number")
		try
		{
			list.addNumber(-10);
			list.addNumber(-10);
			list.addNumber(-20);
			list.addNumber(-30);
			list.addNumber(-50);
		}
		CATCH
		press_any_key();
	}
	SPACER(2)

	{
		MAIN_MSG("add a number when list is already full")
		try
		{
			list.addNumber(40);
		}
		CATCH
		press_any_key();
	}
	SPACER(2)

	{
		MAIN_MSG("valid shortest and longest span")
		try
		{
			PRINT << "Shortest Span: " << list.shortestSpan() << RESEND;
		}
		CATCH
		try
		{
			PRINT << "Longest Span: " << list.longestSpan() << RESEND;
		}
		CATCH
		press_any_key();
	}
	SPACER(2)

	Span list2(100);
	{
		MAIN_MSG("invalid shortest and longest span")
		try
		{
			PRINT << "Shortest Span: " << list2.shortestSpan() << RESEND;
		}
		CATCH
		try
		{
			PRINT << "Longest Span: " << list2.longestSpan() << RESEND;
		}
		CATCH
		press_any_key();
	}
	SPACER(2)

	{
		MAIN_MSG("many numbers in one call")

		std::vector<int> vector1;
		for (int i = 0; i < 100; i++)
			vector1.push_back(i);
		
		try
		{
			list2.addNumber(vector1.begin(), vector1.end());
		}
		CATCH

		try
		{
			PRINT << "Shortest Span: " << list2.shortestSpan() << RESEND;
		}
		CATCH
		try
		{
			PRINT << "Longest Span: " << list2.longestSpan() << RESEND;
		}
		CATCH
		press_any_key();
	}
	SPACER(2)

	return (0);
}

//! SECTION