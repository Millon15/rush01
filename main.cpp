
#include <CursesDisplay.hpp>

#define EXIT_KEY1	27
#define EXIT_KEY2	113
#define EXIT_KEY3	81

#define KEY_ONE		49
#define KEY_TWO		50
#define KEY_THREE	51
#define KEY_FOUR	52
#define KEY_FIVE	53
#define KEY_SIX		54

#define COL_ONE		33
#define COL_TWO		64
#define COL_THREE	35
#define COL_FOUR	36

int				main( void )
{
	// if ( ac > 3 || ac == 2 ) {
	// 	std::cout << "ERROR: Wrong number of arguments" << std::endl;
	// 	std::cout << "usage: ./ft_gkrellm [-c|--colums]" << std::endl;
	// 	return 0;
	// }

	CursesDisplay	d;
	int				inconstant = 0;
	int				c;

	while (true)
	{
		c = getch();
		if ( c == KEY_ONE ) d.switchNames();
		else if ( c == KEY_TWO ) d.switchOSinfo();
		else if ( c == KEY_THREE ) d.switchTime();
		else if ( c == KEY_FOUR ) d.switchCPU();
		else if ( c == KEY_FIVE ) d.switchRAM();
		else if ( c == KEY_SIX ) d.switchNetwork();
		else if ( c == COL_ONE ) d.switchCols(1);
		else if ( c == COL_TWO ) d.switchCols(2);
		else if ( c == COL_THREE ) d.switchCols(3);
		else if ( c == COL_FOUR ) d.switchCols(4);
		else if ( c == EXIT_KEY1 || c == EXIT_KEY2 || c == EXIT_KEY3 )
			break ;

		if ( inconstant == 1000 ) {
			d.refresh();
			inconstant = 0;
		}
		inconstant++;
	}

	return 0;
}
