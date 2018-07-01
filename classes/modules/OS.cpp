/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:44 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/01 17:41:29 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OS.hpp>

OS::OS( void )
{
	return ;
}
OS::OS( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
OS::OS( const OS &toCopy )
{
	*this = toCopy;
}
OS::~OS( void )
{
	return ;
}

OS			&OS::operator=( const OS &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}


void			OS::putInfo( void ) const
{
	int					y = _winStStr;
	const std::string	kernel = saveExec("uname -v");
	const std::string	hardware = saveExec("uname -m");
	const std::string	genInfo = saveExec("sw_vers | sed -e 's/Ver/ ver/' -e 's/Name/ name/' -e 's/\t/ /'");
	std::size_t			spos;
	std::size_t			epos;

	mvwprintw(this->_w, y++, 1, "%s", kernel.substr(0, kernel.find(": ")).c_str());
	mvwprintw(this->_w, y++, 1, "Platform: %s", hardware.c_str());
	epos = genInfo.find('\n');
	mvwprintw(this->_w, y++, 1, "%s", genInfo.substr(0, epos).c_str());
	spos = epos + 1;
	epos = genInfo.find('\n', spos);
	mvwprintw(this->_w, y++, 1, "%s", genInfo.substr(spos, epos).c_str());
	spos = epos + 1;
	epos = genInfo.find('\n', spos);
	mvwprintw(this->_w, y++, 1, "%s", genInfo.substr(spos, epos).c_str());

	this->refresh();
}
