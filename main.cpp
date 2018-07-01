/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:08:33 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/01 15:52:47 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CursesDisplay.hpp>

static void		putError( const char *err )
{
	std::cout << err << std::endl;
	std::cout << "usage: ./ft_gkrellm (-g|-c)" << std::endl;
}

static void			displayCurses( void )
{
	CursesDisplay	d;

	d.run();
}

static void			displayGTK( void )
{
	return ;
}

int				main( int ac, char **av )
{
	pid_t			pid = fork();

	if ( pid == 0 ) { // child process
		system("mkdir -p other");
		system("system_profiler -detailLevel mini > other/sysinfo");
		return 0;
	}
	// else if ( pid > 0 ) { // parent process
	// }
	// else { // fork failed
	// 	return 1;
	// }

	if ( ac > 2 ) {
		putError("ERROR: too much arguments");
	}
	else if ( ac == 2 )
	{
		if ( !strcmp("-g", av[1]) )			displayGTK();
		else if ( !strcmp("-c", av[1]) )	displayCurses();
		else								putError("ERROR: wrong second argument");
	}
	else { // Default behaviour
		displayCurses();
	}

	return 0;
}
