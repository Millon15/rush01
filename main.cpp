
#include <CursesDisplay.hpp>

int				main( void )
{
	CursesDisplay	d;
	int				inconstant = 0;
	int				c;

	while (true)
	{
		c = getch();
		if ( c == KEY_UP ) {
			d.hello();
		}
		else if ( c == EXIT_KEY1 || c == EXIT_KEY2 || c == EXIT_KEY3 ) {
			break ;
		}
		if ( !(inconstant % 1000) ) {
			d.refresh();
			inconstant = 0;
		}
		inconstant++;
	}

	return 0;
}
