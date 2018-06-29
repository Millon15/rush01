
#include <CursesDisplay.hpp>
#include <main.hpp>

int				main( void )
{
	// if ( ac > 3 || ac == 2 ) {
	// 	std::cout << "ERROR: Wrong number of arguments" << std::endl;
	// 	std::cout << "usage: ./ft_gkrellm [-c|--colums]" << std::endl;
	// 	return 0;
	// }

	pid_t			pid = fork();

	if ( pid == 0 ) { // child process
		system("system_profiler -detailLevel mini > sysInfo");
		return 0;
	}
	// else if ( pid > 0 ) { // parent process
	// }
	// else { // fork failed
	// 	return 1;
	// }

	CursesDisplay	d;
	int				inconstant = 0;
	int				c;

	while (true)
	{
		c = getch();
		if ( c == KEY_ONE ) d.switchName();
		else if ( c == KEY_TWO ) d.switchOSinfo();
		else if ( c == KEY_THREE ) d.switchTime();
		else if ( c == KEY_FOUR ) d.switchCPU();
		else if ( c == KEY_FIVE ) d.switchRAM();
		// else if ( c == KEY_SIX ) d.switchNetwork();
		else if ( c == COL_ONE ) d.switchCols(1);
		else if ( c == COL_TWO ) d.switchCols(2);
		else if ( c == COL_THREE ) d.switchCols(3);
		else if ( c == COL_FOUR ) d.switchCols(4);
		else if ( c == EXIT_KEY1 || c == EXIT_KEY2 || c == EXIT_KEY3 )
			break ;

		if ( inconstant == 100000 ) {
			d.refresh();
			inconstant = 0;
		}
		inconstant++;
	}

	return 0;
}
