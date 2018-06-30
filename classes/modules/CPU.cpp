/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:56 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:51:56 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CPU.hpp>

CPU::CPU( void )
{
	return ;
}
CPU::CPU( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
CPU::CPU( const CPU &toCopy )
{
	*this = toCopy;
}
CPU::~CPU( void )
{
	return ;
}

CPU			&CPU::operator=( const CPU &toCopy )
{
	ACursesModule::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}


void		CPU::putInfo( void ) const
{
	int						y = _winStStr;
	const std::string		proc = saveExec("sysctl -n machdep.cpu.brand_string");
	const std::string		proc1 = proc.substr(0, proc.find("(TM) ") + 5);
	const std::string		proc2 = proc.substr(proc.find("(TM) ") + 5);
	const std::string		architecture = saveExec("uname -p");
	const std::string		ncores = saveExec("sysctl hw.ncpu | sed 's/.*: //'");
	const int				n = atoi(ncores.c_str());
	const std::string		usage = saveExec("ps -o %cpu -A | awk '{s+=$1} END {print s}'");
	const int				u = atoi(usage.c_str());

	mvwprintw(this->_w, y++, (__size_x - proc1.length()) / 2, "%s", proc1.c_str());
	mvwprintw(this->_w, y++, (__size_x - proc2.length()) / 2, "%s", proc2.c_str());

	mvwprintw(this->_w, y++, 1, "Processor architecture: %s", architecture.c_str());
	mvwprintw(this->_w, y++, 1, "Cores Number: %s", ncores.c_str());
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "CPU usage: %d%%", u / n);

	this->refresh();
}
