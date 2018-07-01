/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:56 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/01 17:41:19 by vbrazas          ###   ########.fr       */
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
	const std::string		usageUser = saveExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $3;}'");
	const std::string		usageSystem = saveExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $5;}'");
	const std::string		usageIdle = saveExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $7;}'");
	

	mvwprintw(this->_w, y++, (__size_x - proc1.length()) / 2, "%s", proc1.c_str());
	mvwprintw(this->_w, y++, (__size_x - proc2.length()) / 2, "%s", proc2.c_str());

	mvwprintw(this->_w, y++, 1, "Processor architecture: %s", architecture.c_str());
	mvwprintw(this->_w, y++, 1, "Cores Number: %s", ncores.c_str());
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "CPU usage(user): %s", usageUser.c_str());
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "CPU usage(system): %s", usageSystem.c_str());
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "CPU usage(idle): %s", usageIdle.c_str());

	this->refresh();
}
