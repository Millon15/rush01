/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:08:29 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 20:03:12 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

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
#define KEY_SEVEN	'7'
#define KEY_EIGHT	'8'
#define KEY_NINE	'9'

#define COL_ONE		'!'
#define COL_TWO		'@'
#define COL_THREE	'#'
#define COL_FOUR	'$'
#define COL_FIVE	'%'
#define COL_SIX		'^'

std::string					exec( const char * );
std::string					saveExec( const char * );
std::vector<std::string>	explode( const std::string &, const char );
std::string					&trim( std::string & );

#endif
