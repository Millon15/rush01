/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:08:33 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 12:08:37 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CursesDisplay.hpp>
#include <main.hpp>

int				main( void )
{
	pid_t			pid = fork();

	if ( pid == 0 ) { // child process
		system("system_profiler -detailLevel mini > sysinfo");
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
		if ( c == KEY_ONE )				d.switchName();
		else if ( c == KEY_TWO )		d.switchOSinfo();
		else if ( c == KEY_THREE )		d.switchTime();
		else if ( c == KEY_FOUR )		d.switchCPU();
		else if ( c == KEY_FIVE )		d.switchRAM();
		// else if ( c == KEY_SIX )		d.switchNetworkThro();
		else if ( c == KEY_SEVEN )		d.switchNetworkInfo();
		// else if ( c == KEY_EIGHT )		d.switchCat();
		// else if ( c == KEY_NINE )		d.switchHardware();
		else if ( c == COL_ONE )		d.switchCols(1);
		else if ( c == COL_TWO )		d.switchCols(2);
		else if ( c == COL_THREE )		d.switchCols(3);
		else if ( c == COL_FOUR )		d.switchCols(4);
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
