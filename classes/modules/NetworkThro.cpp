/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThro.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:06:46 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 16:55:15 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NetworkThro.hpp>

NetworkThro::NetworkThro( void )
{
	return ;
}
NetworkThro::NetworkThro( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
NetworkThro::NetworkThro( const NetworkThro &toCopy )
{
	*this = toCopy;
}
NetworkThro::~NetworkThro( void )
{
	return ;
}

NetworkThro			&NetworkThro::operator=( const NetworkThro &toCopy )
{
	ACursesModule::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}

void				NetworkThro::putInfo( void ) const
{
	int									y = _winStStr;
	const std::string					all = saveExec("netstat -i -I en0 -b | awk '{print $5, $7, $8, $10}'");
	const std::vector<std::string>		Avec = explode(all, '\n');
	char								*pEnd;
	long int							Ipac = 0, Ibyt = 0, Opac = 0, Obyt = 0;
	static long int						pastIpac = 0, pastIbyt = 0, pastOpac = 0, pastObyt = 0;

	Ipac = strtol (Avec[1].c_str(), &pEnd, 10);
	Ibyt = strtol (pEnd, &pEnd, 10);
	Opac = strtol (pEnd, &pEnd, 10);
	Obyt = strtol (pEnd, NULL, 10);


	mvwprintw(this->_w, y++, 1, "Input packages: %ld MB", Ipac / 1024);
	mvwprintw(this->_w, y++, 1, "Output packages: %ld MB", Opac / 1024);
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "Ipack/sec : %ld B", (Ipac - pastIpac));
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "Opack/sec: %ld B", (Opac - pastOpac));

	mvwprintw(this->_w, y++, 1, "Total input: %ld MB", Ibyt / 1024 / 1024);
	mvwprintw(this->_w, y++, 1, "Total output: %ld MB", Obyt / 1024 / 1024);
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "Itotal/sec : %ld B", (Ibyt - pastIbyt));
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "Ototal/sec: %ld B", (Obyt - pastObyt));


	pastIpac = Ipac;
	pastIbyt = Ibyt;
	pastOpac = Opac;
	pastObyt = Obyt;

	this->refresh();
}
