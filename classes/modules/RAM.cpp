/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:09:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 21:47:59 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RAM.hpp>

RAM::RAM( void )
{
	return ;
}
RAM::RAM( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
RAM::RAM( const RAM &toCopy )
{
	*this = toCopy;
}
RAM::~RAM( void )
{
	return ;
}

RAM			&RAM::operator=( const RAM &toCopy )
{
	ACursesModule::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}


void		RAM::putInfo( void ) const
{
	int					y = _winStStr;
	const std::string	memCap = saveExec("cat other/sysinfo | grep 'Memory: \\d* ' | sed -e 's/^ *//'");
	const std::string	upgradeable = saveExec("cat other/sysinfo | grep 'Upgradeable Memory:' | sed 's/^ *//'");
	const std::string	banks = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | grep 'BANK' | wc -l | sed 's/^ *//'");
	const std::string	types = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Type:/  {printf \"%s \", $2;}'");
	const std::string	sizes = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Size:/  {printf \"%s \", $2$3;}'");
	const std::string	speed = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Speed:/  {printf \"%s \", $2$3;}'");

	mvwprintw(this->_w, y++, 1, "%s", memCap.c_str());
	mvwprintw(this->_w, y++, 1, "%s", upgradeable.c_str());
	mvwprintw(this->_w, y++, 1, "Memory slots: %s", banks.c_str());

	mvwprintw(this->_w, y++, alignCenter(13), "Slots' types:");
	mvwprintw(this->_w, y++, alignCenter(types), "%s", types.c_str());
	mvwprintw(this->_w, y++, alignCenter(13), "Slots' sizes:");
	mvwprintw(this->_w, y++, alignCenter(sizes), "%s", sizes.c_str());
	mvwprintw(this->_w, y++, alignCenter(13), "Slots' speed:");
	mvwprintw(this->_w, y++, alignCenter(speed), "%s", speed.c_str());

	this->refresh();
}
