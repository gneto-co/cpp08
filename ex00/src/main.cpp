#include "../includes/easyfind.tpp"
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
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(42);
	vec.push_back(50);

	{
		MAIN_MSG("existent number")
		try
		{
			PRINT << *easyfind(vec, 42) << " exist" << RESEND;
		}
		CATCH
		press_any_key();
	}
	SPACER(2)

	{
		MAIN_MSG("non existent number")
		try
		{
			PRINT << *easyfind(vec, 43) << " exist" << RESEND;
		}
		CATCH
		press_any_key();
	}
	SPACER(2)

	return (0);
}

//! SECTION