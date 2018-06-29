#ifndef MAIN_HPP
# define MAIN_HPP

#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

#define EXIT_KEY1	27		// escape button
#define EXIT_KEY2	'q'
#define EXIT_KEY3	'Q'

#define KEY_ONE		'1'
#define KEY_TWO		'2'
#define KEY_THREE	'3'
#define KEY_FOUR	'4'
#define KEY_FIVE	'5'
#define KEY_SIX		'6'

#define COL_ONE		'!'
#define COL_TWO		'@'
#define COL_THREE	'#'
#define COL_FOUR	'$'

std::string		exec( const char *cmd );
std::string		saveExec( const char *cmd );

#endif
