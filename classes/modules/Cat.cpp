/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:52:00 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/01 17:41:15 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat( void ) : _kitty()
{
	kittyInit();
}
Cat::Cat( std::string a, int b ) : ACursesModule(a, b), _kitty()
{
	kittyInit();
}
Cat::Cat( const Cat &toCopy )
{
	*this = toCopy;
}
Cat::~Cat( void )
{
	return ;
}
Cat			&Cat::operator=( const Cat &toCopy )
{
	ACursesModule::operator=(toCopy);
	_kitty = toCopy._kitty;

	return *this;
}


void		Cat::kittyInit( void )
{
	_kitty.push_back("               ______       ");
	_kitty.push_back("              |      |____  ");
	_kitty.push_back("              |      |    \\ ");
	_kitty.push_back("              |______|    | ");
	_kitty.push_back("   /\\**/\\     |      |____| ");
	_kitty.push_back("  ( o_o  )_   |             ");
	_kitty.push_back("   (u--u   \\_ |             ");
	_kitty.push_back("    (||___   )^\\            ");
	_kitty.push_back("  ,dP\"/b/=(  /P\"/b\\         ");
	_kitty.push_back("  |8 || 8\\===  || 8         ");
	_kitty.push_back("  `b,  ,P   `b,  ,P         ");
	_kitty.push_back("    \"\"\"`      \"\"\"`          ");

	_kitty.push_back("               ___________");
	_kitty.push_back("              |          /");
	_kitty.push_back("              |          |");
	_kitty.push_back("              |__________|");
	_kitty.push_back("   /\\**/\\     |           ");
	_kitty.push_back("  (  o_o )_   |           ");
	_kitty.push_back("   (n--n   \\_ |           ");
	_kitty.push_back("    (||___   )^\\          ");
	_kitty.push_back("  ,oL\"\\b\\=(--/L\"\\o\\       ");
	_kitty.push_back("  |9 _  9\\===  -  9       ");
	_kitty.push_back("  `o,  ,L   `o,  ,L       ");
	_kitty.push_back("    `''`      `''`        ");
}
void		Cat::putInfo( void ) const
{
	int					y = _winStStr + 1;

	static const std::vector<std::string>::size_type	part = _kitty.size() / 2;// 2 is number of frames
	static std::vector<std::string>::size_type			start = 0;
	static std::vector<std::string>::size_type			end = part;

	for (	std::vector<std::string>::size_type i = start;
			i < end;
			i++ )
	{
		if ( !(i % 2) )		wattron( _w, COLOR_PAIR(CAT1) );
		else				wattron( _w, COLOR_PAIR(CAT2) );
	
		clearLine(y);
		mvwprintw(this->_w, y++, 1, "%s", _kitty[i].c_str());

		if ( !(i % 2) )		wattroff( _w, COLOR_PAIR(CAT1) );
		else				wattroff( _w, COLOR_PAIR(CAT2) );
	}

	if ( end != _kitty.size() ) {
		start += part;
		end += part;
	}
	else {
		start = 0;
		end = part;
	}

	this->refresh();
}
