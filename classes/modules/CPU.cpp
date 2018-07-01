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

CPU::CPU( GtkWidget *window ) : AGUIModule(window), _isHUI(true)
{
	return ;
}
CPU::CPU( std::string a, int b ) : ACursesModule(a, b), _isHUI(false)
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
	const std::string		proc = saveExec("sysctl -n machdep.cpu.brand_string");
	const std::string		proc1 = proc.substr(0, proc.find("(TM) ") + 5);
	const std::string		proc2 = proc.substr(proc.find("(TM) ") + 5);
	const std::string		architecture = saveExec("uname -p");
	const std::string		ncores = saveExec("sysctl hw.ncpu | sed 's/.*: //'");
	const std::string		usageUser = saveExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $3;}'");
	const std::string		usageSystem = saveExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $5;}'");
	const std::string		usageIdle = saveExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $7;}'");
	
	if ( _isHUI ) {
		std::vector<std::string>	HUI;
		GtkWidget*					tmp;


		HUI.push_back(proc);
		HUI.push_back(proc1);
		HUI.push_back(proc2);
		HUI.push_back(architecture);
		HUI.push_back(ncores);
		HUI.push_back(usageUser);
		HUI.push_back(usageSystem);
		HUI.push_back(usageIdle);
		
		for ( int i = 0; i < 8; i++ ) {
			tmp = gtk_label_new(HUI[i].c_str());
			gtk_container_add(GTK_CONTAINER(_win),  tmp);
			// _lables.push_back( tmp );
			// gtk_widget_show( *_lables.end() );
		}		
		// AGUIModule::refresh(_lables, HUI);
	}
	else {
		int						y = _winStStr;

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
		ACursesModule::refresh();
	}
}
